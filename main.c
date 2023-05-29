#include <stdio.h>
#include "linkedlist.h"

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

    puts("");

    Node* anotha = linkedlist_lookup_int(list, 5);
    
}