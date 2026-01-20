#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
} *first = NULL, *last = NULL;

// 1. Insert at Beginning
void insertatbeg() {
    struct node *newnode;
    int data;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory is full\n");
        exit(1);
    }
    printf("Enter data: ");
    scanf("%d", &data);
    newnode->prev = NULL;
    newnode->data = data;
    newnode->next = NULL;

    if (first == NULL) {
        first = newnode;
        last = newnode;
        last->next = newnode;
        first->prev = newnode;
    } else {
        newnode->next = last->next; 
        first->prev = newnode;
        first = newnode;
        last->next = first;
        first->prev = last;
    }
}

// 2. Insert at End
void insertatend() {
    struct node *newnode, *temp;
    int data;
    newnode = (struct node