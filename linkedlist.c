#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

#define DEFAULT_SIZE 0

Node* node_create(void* data) {
    Node* node = malloc(sizeof(Node));
    if (!node) {
        puts("malloc failed");
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}

LinkedList* linkedlist_init() {
    LinkedList* list = malloc(sizeof(LinkedList));
    if (!list) {
        puts("malloc failed.");
        return NULL;
    };
    list->head = NULL;
    list->size = DEFAULT_SIZE;
    return list;
}

int linkedlist_get_size(LinkedList* list) {
    return list->size;
}

int linkedlist_is_empty(LinkedList* list) {
    return list->size == 0;
}

void linkedlist_push_front(LinkedList* list, Node* node) {
    if (list->size == 0) {
        list->tail = node;
    }
    node->next = list->head;
    list->head = node;
    list->size++;
}

void linkedlist_push_back(LinkedList* list, Node* node) {
    if (list->size == 0) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
    list->size++;
}

void* linkedlist_pop_front(LinkedList* list) {
    if (list->size == 0) {
        puts("Empty list.");
        return NULL;
    }
    Node* popped = list->head;
    list->head = list->head->next;

    void* data = popped->data;
    free(popped);

    list->size--;

    return data;
}

void* linkedlist_pop_back(LinkedList* list) {
    void* data = NULL;
    if (list->size == 0) {
        puts("Empty list.");
        return NULL;
    } else if (list->size == 1) {
        puts("In else if");
        data = list->head->data;
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    } else {
        Node* prev_node = list->head;
        while(prev_node->next->next != NULL) {
            prev_node = prev_node->next;
        }
        data = prev_node->next->data;
        list->tail = prev_node;
        free(prev_node->next);
        prev_node->next = NULL;
    }
    
    list->size--;

    return data;
}

void linkedlist_insert(LinkedList* list, Node* node, int index) {
    if (0 > index || index > list->size) {
        puts("Index out of bounds");
        return;
    }
    Node* temp_node = list->head;
    if (index == 0) {
        node->next = list->head;
        list->head = node;
    } else if (index == 1) {
        node->next = list->head->next;
        list->head->next = node;
    } else {
        for (int i = 0; i < index-1; i++) {
            temp_node = temp_node->next;
            printf("Value: %d\n", *(int*)temp_node->data);
        }
        node->next = temp_node;
        temp_node->next = node;
    }
    list->size++;
}

Node* linkedlist_access(LinkedList* list, int index) {
    if (0 > index || list->size <= index) {
        puts("index out of bounds");
        return NULL;
    }
    Node* node = list->head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    return node;
}

void linkedlist_delete(LinkedList* list, int index) {
    if (index < 0 || index >= list->size) { 
        puts("Index out of bounds");
        return;
    }

    Node* node;
    if (index == 0) {
        node = list->head->next;
        free(list->head);
        list->head = node;
        if (list->size == 1) {  // added condition to update tail if list has only 1 node
            list->tail = node;
        }
    } else {
        node = list->head;
        for (int i = 0; i < index - 1; i++) {
            node = node->next;
        }
        Node* node_to_delete = node->next;
        if (node_to_delete == list->tail) {  // added condition to update tail if last node is deleted
            list->tail = node;
        }
        node->next = node->next->next;
        free(node_to_delete);
    }
    list->size--;
}

Node* linkedlist_lookup_int(LinkedList* list, int value) {
    Node* node = list->head;
    while(node != NULL) {
        if (*(int*)node->data == value) {
            puts("Succesful lookup.");
            return node;
        }
        node = node->next;
    }
    puts("No matches found.");
    return NULL;
}

void linkedlist_print_all(LinkedList* list) {
    if (list->size == 0) {
        puts("List is empty!");
        return;
    }
    Node* node = list->head;
    for (int i = 0; i < list->size; i++) {
        printf("%d. %d\n", i, *(int*)node->data);
        node = node->next;
    }
}

void linkedlist_destroy(LinkedList* list) {
    if (list->size == 0) {
        puts("List is empty!!!");
        return;
    }
    Node* node = list->head;
    printf("Size before loop: %d\n", list->size);
    while (node != NULL) {
        Node* next_node = node->next;
        free(node);
        node = next_node;
        list->size--;
    }
    printf("Size after loop: %d\n", list->size);
    list->head = NULL;
    list->tail = NULL;
}
