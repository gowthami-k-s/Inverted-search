#include "header.h"

// Search the word in database
void search_word(Hash_t *arr)
{
    char word[100];
    printf("Enter the word to search: ");
    scanf("%99s", word);

    // Convert the entered word to lower case
    for(int i = 0; word[i]; i++)
    {
        if(word[i] >= 'A' && word[i] <= 'Z')
        {
            word[i] = word[i] + 32;
        }
    }

    // Calculate the index
    int index;
    if(word[0] >= 'a' && word[0] <= 'z')
    {
        index = word[0] - 'a';
    }
    else
    {
        index = 26;
    }

    // Search for the word in the main node list
    Main_node *temp = arr[index].link;
    while(temp != NULL)
    {
        // If word is found display filenames and their word counts
        if(strcmp(temp->word, word) == 0)
        {
            printf("\nWord found in the following files: \n");
            Sub_node *sub = temp->slink;
            while(sub != NULL)
            {
                printf("File Name: %s, Word count: %d\n\n", sub->f_name, sub->w_count);
                sub = sub->link;
            }
            return;
        }
        temp = temp->mlink;
    }
    printf("\nWord not found in the database.\n");
}