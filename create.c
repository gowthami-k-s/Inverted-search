#include "header.h"

void create_database(Hash_t *arr, F_list *head)
{
    // Check weather files are available
    if(head == NULL)
    {
        printf("No files to process.\n");
        return;
    }

    while(head != NULL)
    {
        // Open the File for reading
        char *file_name = head->f_name;
        FILE *fp = fopen(file_name, "r");
        if(fp == NULL)
        {
            printf("Error opening file : %s\n", file_name);
            head = head->link;
            continue;
        }

        char word[100];
        while(fscanf(fp, "%99s", word) != EOF)
        {
            int index;
            // Convert word to lower case
            for(int i = 0; word[i]; i++)
            {
                if(word[i] >= 'A' && word[i] <= 'Z')
                {
                    word[i] = word[i] + 32;
                }
            }

            // Calculate the index
            if(word[0] >= 'a' && word[0] <= 'z')
            {
                index = word[0] - 'a';
            }
            else
            {
                index = 26;
            }

            // Insert the word into hash table
            arr[index].link = insert_word(arr[index].link, word, file_name);
        }

        // Close the file after reading
        fclose(fp);
        head = head->link;
    }

    printf("\n\"Database created successfully.\"\n\n");
}

Main_node *insert_word(Main_node *head, char *word, char *file_name)
{
    // If the head is null create a new main node and add the word into database
    if(head == NULL)
    {
        Main_node *new = malloc(sizeof(Main_node));
        new->word = malloc(strlen(word)+1);
        strcpy(new->word, word);
        new->f_count = 1;

        new->slink = malloc(sizeof(Sub_node));
        new->slink->f_name = malloc(strlen(file_name)+1);
        strcpy(new->slink->f_name, file_name);
        new->slink->w_count = 1;
        new->slink->link = NULL;

        new->mlink = NULL;
        return new;
    }

    Main_node *temp = head;
    while(temp != NULL)
    {
        // Check whether the word is already present in data base or not.
        if(strcmp(temp->word, word) == 0)
        {
            Sub_node *sub = temp->slink;
            while(sub != NULL)
            {
                // If present add file name and increase the word count and file count
                if(strcmp(sub->f_name, file_name) == 0)
                {
                    sub->w_count++;
                    return head;
                }
                sub = sub->link;
            }

            // If not present create new sub node and add the filename
            Sub_node *new_sub = malloc(sizeof(Sub_node));
            new_sub->f_name = malloc(strlen(file_name)+1);
            strcpy(new_sub->f_name, file_name);
            new_sub->w_count = 1;
            new_sub->link = NULL;

            sub = temp->slink;
            while(sub->link != NULL)
            {
                sub = sub->link;
            }

            sub->link = new_sub;
            temp->f_count++;
            return head;
        }

        // Insert the word in alphabetical order
        else if(strcmp(temp->word, word) > 0)
        {
            Main_node *new = malloc(sizeof(Main_node));
            new->word = malloc(strlen(word)+1);
            strcpy(new->word, word);
            new->f_count = 1;

            new->slink = malloc(sizeof(Sub_node));
            new->slink->f_name = malloc(strlen(file_name)+1);
            strcpy(new->slink->f_name, file_name);
            new->slink->w_count = 1;
            new->slink->link = NULL;
            new->mlink = NULL;

            if(temp == head)
            {
                new->mlink = head;
                return new;
            }
            else
            {
                Main_node *prev = head;
                while(prev->mlink != temp)
                {
                    prev = prev->mlink;
                }
                new->mlink = temp;
                prev->mlink = new;
                return head;
            }
        }

        // Insert new node at the end of the list if it is not found
        else
        {
            if(temp->mlink == NULL)
            {
                Main_node *new = malloc(sizeof(Main_node));
                new->word = malloc(strlen(word)+1);
                strcpy(new->word, word);
                new->f_count = 1;

                new->slink = malloc(sizeof(Sub_node));
                new->slink->f_name = malloc(strlen(file_name)+1);
                strcpy(new->slink->f_name, file_name);
                new->slink->w_count = 1;
                new->slink->link = NULL;

                new->mlink = NULL;
                temp->mlink = new;
                return head;
            }
        }
        temp = temp->mlink;
    }
    return head;
}