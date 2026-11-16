#include "header.h"

void save_database(Hash_t *arr)
{
    char file_name[100];
    FILE *fp = NULL;
    while(1)
    {
        // Take the filename form the user
        printf("Enter the file name to save the database: ");
        scanf(" %s", file_name);

        // Validate the file name
        char *ext = strrchr(file_name, '.');
        if(ext == NULL || strcmp(ext, ".txt") != 0)
        {
            printf("Invalid file extension. Only .txt files are allowed.\n");
            continue;
        }

        // Check if the file already present or not
        fp = fopen(file_name, "r");
        if(fp != NULL)
        {
            fclose(fp);
            printf("File already exists.\n");
            printf("1. Overwrite the file\n2. Enter new file name\nEnter your choice: ");
            char choice;
            scanf(" %c", &choice);
            if(choice == '1')
            {
                fp = fopen(file_name, "w");
                if(fp == NULL)
                {
                    printf("Error opening file : %s\n", file_name);
                    return;
                }
                break;
            }
            else if(choice == '2')
            {
                continue;
            }
            else
            {
                printf("Invalid choice. Please try again.\n");
                continue;
            }
        }
        else
        {
            fp = fopen(file_name, "w");
            break;
        }
    }

    // Save the word details into the file
    for(int i = 0; i < SIZE; i++)
    {
        if(arr[i].link != NULL)
        {
            Main_node *temp = arr[i].link;
            while(temp != NULL)
            {
                fprintf(fp, "#%d;%s;%d;", arr[i].index, temp->word, temp->f_count);
                Sub_node *sub = temp->slink;
                while(sub != NULL)
                {
                    fprintf(fp, "%s;%d;", sub->f_name, sub->w_count);
                    sub = sub->link;
                }
                fprintf(fp, "#\n");
                temp = temp->mlink;
            }
        }
    }

    // Close the file after saving
    fclose(fp);
    printf("\n\"Database saved succesfully to file: %s\"\n\n", file_name);
}