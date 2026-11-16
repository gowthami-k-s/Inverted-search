#include "header.h"

void update_database(Hash_t *arr)
{
    // Get the filename from the user
    char file_name[100], line[1000];
    printf("Enter the file name to update the database: ");
    scanf("%s", file_name);
    FILE *fp = NULL;

    // Validate the filename
    char *ext = strrchr(file_name, '.');
    if(ext == NULL || strcmp(ext, ".txt") != 0)
    {
        printf("Invalid file extension. Only .txt files are allowed.\n");
        return;
    }

    // Open the file and check if it is empty or not
    fp = fopen(file_name, "r");
    if(fp == NULL)
    {
        printf("Error opening file : %s\n", file_name);
        return;
    }

    if(fgetc(fp) == EOF)
    {
        printf("File is empty. No words to update.\n");
        fclose(fp);
        return;
    }

    rewind(fp);
    
    // Read the word entries line by line
    while(fgets(line, sizeof(line), fp) != NULL)
    {
        char *token = strtok(line, ";#\n");

        if(token == NULL)
        {
            continue;
        }

        int index = atoi(token);
        if(index < 0 || index >= SIZE)
            continue;

        // Extract word
        token = strtok(NULL, ";#\n");

        if(token == NULL)
            continue;

        char word[100];
        strcpy(word, token);

        // Extract file count
        token = strtok(NULL, ";#\n");

        if(token == NULL)
            continue;

        int f_count = atoi(token);

        // Extract filename and word count
        while(1)
        {
            char *f_name = strtok(NULL, ";#\n");

            if(f_name == NULL)
                break;

            char file[100];
            strcpy(file, f_name);

            char *w_count = strtok(NULL, ";#\n");

            if(w_count == NULL)
                break;

            int count = atoi(w_count);

            // Insert word and filename
            arr[index].link = insert_word(arr[index].link, word, file);

            // Find inserted main node
            Main_node *temp = arr[index].link;

            while(temp != NULL)
            {
                if(strcmp(temp->word, word) == 0)
                    break;

                temp = temp->mlink;
            }

            // Update word count in sub node
            if(temp != NULL)
            {
                Sub_node *sub = temp->slink;

                while(sub != NULL)
                {
                    if(strcmp(sub->f_name, file) == 0)
                    {
                        sub->w_count = count;
                        break;
                    }

                    sub = sub->link;
                }

                temp->f_count = f_count;
            }
        }
    }

    fclose(fp);

    printf("\n\"Database updated successfully.\"\n\n");
}