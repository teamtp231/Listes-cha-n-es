#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


void insertSorted(Node** head_ref, int new_data) {
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = NULL;

    
    if (*head_ref == NULL || (*head_ref)->data >= new_data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        
        Node* current = *head_ref;
        while (current->next != NULL && current->next->data < new_data) {
            current = current->next;
        }
        
        new_node->next = current->next;
        current->next = new_node;
    }
}


void printList(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    printf("Insertion de 5...\n");
    insertSorted(&head, 5);
    printList(head);

    printf("Insertion de 10...\n");
    insertSorted(&head, 10);
    printList(head);

    printf("Insertion de 3...\n");
    insertSorted(&head, 3);
    printList(head);

    printf("Insertion de 8...\n");
    insertSorted(&head, 8);
    printList(head);

    printf("Insertion de 12...\n");
    insertSorted(&head, 12);
    printList(head);

    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}
