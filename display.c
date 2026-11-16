#include "header.h"

void display_database(Hash_t *arr)
{
    // Display the database based on the hash table
    printf("Displaying Database:\n");
    printf("%-10s%-15s%-15s%-20s%-10s\n", "Index", "Word", "File count", "File Name", "Word count");
    for(int i = 0; i < SIZE; i++)
    {
        if(arr[i].link != NULL)
        {
            Main_node *temp = arr[i].link;
            while(temp != NULL)
            {
                printf("%-10d%-15s%-15d", arr[i].index, temp->word, temp->f_count);
                Sub_node *sub = temp->slink;
                while(sub != NULL)
                {
                    printf("%-20s%-10d\n", sub->f_name, sub->w_count);
                    sub = sub->link;
                    printf("%-40s", " ");
                }
                printf("\n");
                temp = temp->mlink;
            }
        }
    }
    printf("\n");
}