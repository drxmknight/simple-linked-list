#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init(List *list) {
    list->first = NULL;
}

void push_first(List *list, int value) {
    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = list->first;
    list->first = new_node;
}

void push_last(List *list, int value) {
    Node *temp = list->first;

    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;

    if (temp == NULL) {
        list->first = new_node;
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
}

int pop_last(List *list) {
    int result;
    Node *first = list->first;

    if (first == NULL) {
        printf("List is Empty!\n");
        return -1;
    }

    list->first = first->next;
    result = first->value;
    free(first);
    return result;
}

int pop_first(List *list) {
    int result;
    Node *last = list->first;
    Node *second_last = last;

    if (last == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }

    while (last->next != NULL) {
        second_last = last;
        last = last->next;
    }

    if (last == list->first)
        list->first = NULL;

    result = last->value;
    second_last->next = NULL;
    free(last);

    return result;
}

void print_list(List list) {
    Node *last = list.first;
    printf("List: ");

    if (last == NULL)
        printf("Empty!");

    while (last != NULL) {
        printf("%d ", last->value);
        last = last->next;
    }
    printf("\n");
}

void free_list(List *list) {
    Node *temp = list->first;
    while (temp != NULL) {
        list->first = temp->next;
        free(temp);
        temp = list->first;
    }
    printf("List cleaned!\n");
}