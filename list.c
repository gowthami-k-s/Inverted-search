#include "header.h"

// Creating the lined list for filenames
void create_file_list(F_list **head, char *name)
{
    // Allocate memory for new node
    F_list *new = malloc(sizeof(F_list));
    if(new == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    // Allocate memory to store filename and copy the filename
    new->f_name = malloc(strlen(name) +1);
    if(new->f_name == NULL)
    {
        printf("Memory allocation failed.\n");
        free(new);
        return;
    }

    strcpy(new->f_name, name);
    new->link = NULL;

    // Insert the new node at the end of the list
    if(*head == NULL)
    {
        *head = new;
    }
    else
    {
        F_list *temp = *head;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new;
    }
}

// Initialize all hash table entries
void initialize_hash(Hash_t *arr)
{
    for(int i = 0; i < 27; i++)
    {
        arr[i].index = i;
        arr[i].link = NULL;
    }
}

void remove_duplicate_and_empty_files(F_list **head)
{
    F_list *temp = *head;
    F_list *prev = NULL;
    F_list *next = NULL;

    // Remove duplicate filenames from the list
    while(temp != NULL)
    {
        prev = temp;
        next = temp->link;
        while(next != NULL)
        {
            if(strcmp(temp->f_name, next->f_name) == 0)
            {
                prev->link = next->link;
                free(next->f_name);
                free(next);
                next = prev->link;
            }
            else
            {
                prev = next;
                next = next->link;
            }
        }
        temp = temp->link;
    }

    // Remove empty files
    temp = *head;
    prev = NULL;
    while(temp != NULL)
    {
        FILE *fp = fopen(temp->f_name, "r");

        if(fp == NULL)
        {
            printf("Error opening file : %s\n", temp->f_name);
        }
        else
        {
            int ch = fgetc(fp);
            fclose(fp);

            if(ch != EOF)
            {
                prev = temp;
                temp = temp->link;
                continue;
            }
        }
        F_list *del = temp;
        temp = temp->link;

        if(prev == NULL)
            *head = temp;
        else
            prev->link = temp;

        free(del->f_name);
        free(del);
    }
}
