#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 0

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
    size_t size;
} LinkedList;

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

void linkedlist_insert(LinkedList* list, Node* node, int index) {
    if (index > list->size) {
        puts("Index out of bounds");
        return;
    }
    Node* temp_node = list->head;
    puts("Before loop");
    if (index == 0) {
        list->head;
    }
    for (int i = 0; i < index-1; i++) {
        puts("In loop");
        temp_node = temp_node->next;
        printf("Value: %d\n", *(int*)temp_node->data);
    }
    node->next=temp_node;
    temp_node=node;
}

void linkedlist_print_all(LinkedList* list) {
    Node* node = list->head;
    for (int i = 0; i < list->size; i++) {
        printf("%d. %d\n", i, *(int*)node->data);
        node = node->next;
    }
}

int main() {

    int a = 5, b = 10, c = 15;
    Node* node_a;
    node_a = node_create(&a);

    Node* node_b;
    node_b = node_create(&b);

    Node* node_c;
    node_c = node_create(&c);

    LinkedList* list;
    list = linkedlist_init();

    linkedlist_push_back(list, node_a);

    linkedlist_push_front(list, node_b);

    linkedlist_insert(list, node_c, 1);

    linkedlist_print_all(list);

}