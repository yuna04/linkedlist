#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h>

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
    size_t size;
} LinkedList;

Node* node_create(void* data);
LinkedList* linkedlist_init();
void linkedlist_push_front(LinkedList* list, Node* node);
void linkedlist_push_back(LinkedList* list, Node* node);
void* linkedlist_pop_front(LinkedList* list);
void* linkedlist_pop_back(LinkedList* list);
void linkedlist_insert(LinkedList* list, Node* node, int index);
Node* linkedlist_access(LinkedList* list, int index);
void linkedlist_delete(LinkedList* list, int index);
Node* linkedlist_lookup_int(LinkedList* list, int value);
void linkedlist_print_all(LinkedList* list);
void linkedlist_destroy(LinkedList* list);

#endif // LINKEDLIST_H