#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define SIZE 27
#define SUCCESS 1
#define FAILURE 0

// Structure to store filenames
typedef struct list
{
    char *f_name;
    struct list *link;
}F_list;

// Structure of subnode
typedef struct sub
{
    char *f_name;
    int w_count;
    struct sub *link;
}Sub_node;

// Structure of main node
typedef struct main
{
    char *word;
    int f_count;
    struct main *mlink;
    Sub_node *slink;
}Main_node;

// Structure of hash table
typedef struct hash
{
    int index;
    Main_node *link;
}Hash_t;

// Function declarations
int validate_arguments(int argc, char *argv[], F_list **head);
void create_file_list(F_list **head, char *name);
void initialize_hash(Hash_t *arr);
void remove_duplicate_and_empty_files(F_list ** head);
Main_node *insert_word(Main_node *head, char *word, char *file_name);

void create_database(Hash_t *arr, F_list *head);
void display_database(Hash_t *arr);
void search_word(Hash_t *arr);
void save_database(Hash_t *arr);
void update_database(Hash_t *arr);

#endif