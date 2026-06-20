#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#define NULL ((void *)0)


void list_init(List *l) {
    if(l == NULL) {
        return;
    }
    l->head = NULL;
    l->size = 0;
}

void list_push_front(List *l, int value) {
    if(l == NULL) {
        return;
    }
    Node *tmp = calloc(1, sizeof(Node));
    if(tmp == NULL) {
        return;
    }
    tmp->data = value;

    tmp->next =  l->head;
    l->head = tmp;
    l->size++;
}

void list_push_back(List *l, int value) {
    if(l == NULL) {
        return;
    }
    Node *tmp = calloc(1, sizeof(Node));
    if(tmp == NULL) {
        return;
    }

    tmp->data = value;

    if(l->size == 0) {
        l->head = tmp;
    } else {
        Node *lastNode = l->head;
        for(int i = 0; i < l->size - 1; i++) {
            lastNode = lastNode->next;
        }
        lastNode->next = tmp;
    }
    l->size++;
}

void list_print(const List *l) {
    Node *current = l->head;    
    for(int i = 0; i < l->size; i++) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void list_free(List *l) {
    if(l == NULL || l->size == 0) {
        return;
    }
    Node * lastNode = NULL;
    Node * currentNode = l->head;
    
    for(int i = 0; i < l->size; i++) {
        lastNode = currentNode;
        currentNode = currentNode->next;
        free(lastNode);
    }

    l->size = 0;
    l->head = NULL;
}