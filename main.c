/* Name : K S Gowthami
Description :  Inverted search using hashing and linked list
Date : 02-11-2026 */
#include "header.h"

// Mian function to control the program
int main(int argc, char *argv[])
{
    F_list *head = NULL;
    
    // Validate command line arguments
    if(validate_arguments(argc, argv, &head) == FAILURE)
    {
        printf("Invalid arguments.\n");
        return 0;
    }

    // Remove duplicate and empty files
    remove_duplicate_and_empty_files(&head);

    // Initialize hash table
    Hash_t arr[SIZE];
    initialize_hash(arr);

    int ch;
    int create_flag = 0;
    int update_flag = 0;

    do
    {
        // Display the menu
        printf("1. Create Database\n");
        printf("2. Display Database\n");
        printf("3. Search word\n");
        printf("4. Save Database\n");
        printf("5. Update Database\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            // Create database
            case 1:
                // Check whether database creation is allowed 
                if(create_flag == 0)
                {
                    create_database(arr, head);
                    create_flag = 1;
                }
                else
                {
                    printf("Database can only be created once.\n");
                }
                break;
            
            // Display database
            case 2:
                display_database(arr);
                break;

            // Search for word in database
            case 3:
                search_word(arr);
                break;

            // Save the database into a file
            case 4:
                save_database(arr);
                break;

            // Update database from the backup file
            case 5:
                //Check whether database updation is allowed 
                if(create_flag == 0 && update_flag == 0)
                {
                    update_database(arr);
                }
                else
                {
                    printf("\nDatabase update is not allowed.\n\n");
                }
                break;

            // Exit the program
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }while(1);
}

int validate_arguments(int argc, char *argv[], F_list **head)
{
    // Check if command line arguments are given
    if(argc == 1)
    {
        return FAILURE;
    }

    // Validate file extension and create file list
    for(int i = 1; i < argc; i++)
    {
        char *ext = strrchr(argv[i], '.');
        if(ext == NULL || strcmp(ext, ".txt") != 0)
        {
            printf("Invalid File extension for file %s.\n", argv[i]);
            printf("Only .txt files are allowed.\n");
            return FAILURE;
        }
        else
        {
            // Add file name to the linked list
            create_file_list(head, argv[i]);
        }
    }
    return SUCCESS;
}