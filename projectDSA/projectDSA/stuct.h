#ifndef SLL_H
#define SLL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1

typedef int data_t;
typedef struct node
{
    char filename[30];
    struct node *link;

}slist;
typedef struct word_node
{
    int fc;
    char wname[50];
    struct word_node *wlink;
    struct file_node *flink;
}word_node;

typedef struct file_node
{
    int wc;
    char fname[50];
    struct file_node *flink;
}filenode;

int read_and_validate(slist **head, char *argv[], int argc);
int creat_database(slist **head,word_node *word[]);
int display(word_node *word[]);
int search(word_node *word[]);
int save_db(word_node *word[]);
int update_database(word_node *word[]);


#endif
