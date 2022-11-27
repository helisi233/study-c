//
// Created by helisi on 2022/8/9.
//
#include <stdio.h>
#include <stdlib.h>
#include "include/Print_Utils.h"

typedef struct Node {
    int val;
    struct Node *next;
}Node;

Node *CreateNode(int value) {
    Node *node = malloc(sizeof(Node));
    if(!node) exit(1);
    node -> val = value;
    node -> next = NULL;
    return node;
}

void DestroyNode(Node **node) {
    (*node) -> next = NULL;
    free(*node);
    *node = NULL;
}

Node *CreateList(int array[], int length) {
    Node *head = CreateNode(array[0]);
    Node *cur = head;
    for (int i = 1; i < length; ++i) {
        cur->next = CreateNode(array[i]);
        cur = cur->next;
    }
    return head;
}

void DestroyList(Node **head) {
    if(!(*head)) exit(1);
    Node *cur = *head;
    while (cur) {
        Node *destroyNode = cur;
        cur = cur->next;
        DestroyNode(&destroyNode);
    }
    *head = NULL;
}

void PrintList(Node *head) {
    if(!head) exit(1);
    while(head) {
        printf("%d,", head->val);
        head = head->next;
    }
}

void InsertNode(Node **head, int value, int index) {
    if(!head || index < 0) return;
    Node *new_node = CreateNode(value);
    if(index == 0) {
        new_node -> next = *head;
        *head = new_node;
    }else {
        if(!(*head)) {
            *head = CreateNode(0);
        }
        Node *cur = *head;
        while(index > 1) {
            if(!cur->next) {
                cur->next = CreateNode(0);
            }
            cur = cur -> next;
            index --;
        }
        new_node->next = cur->next;
        cur->next = new_node;
    }
}

int main(void) {

    int array[] = {1,2,3,4,5,6};
    Node *head = CreateList(array, 6);
    PrintList(head);
    printf("\n");
    InsertNode(&head, 10, 10);
    PrintList(head);
    DestroyList(&head);

    return 0;
}