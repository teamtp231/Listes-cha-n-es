#include <stdio.h>
#include <stdlib.h>

// Définition de la structure d'un nœud de la liste
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Fonction pour créer un nouveau nœud
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fonction pour insérer un élément en tête de la liste
void insertHead(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

// Fonction pour insérer un élément en queue de la liste
void insertTail(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Fonction pour afficher la liste
void printList(Node* head) {
    if (head == NULL) {
        printf("Liste vide.\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(retour à la tête)\n");
}

// Fonction pour libérer la mémoire de la liste
void freeList(Node** head) {
    if (*head == NULL) {
        return;
    }
    Node* temp = *head;
    Node* next;
    do {
        next = temp->next;
        free(temp);
        temp = next;
    } while (temp != *head);
    *head = NULL;
}

int main() {
    Node* head = NULL; // Initialisation de la liste vide
    int choix, data;

    while (1) {
        printf("Menu:\n");
        printf("1. Insérer un élément en tête de la liste\n");
        printf("2. Insérer un élément en queue de la liste\n");
        printf("3. Afficher la liste\n");
        printf("4. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez la valeur de l'élément : ");
                scanf("%d", &data);
                insertHead(&head, data);
                break;
            case 2:
                printf("Entrez la valeur de l'élément : ");
                scanf("%d", &data);
                insertTail(&head, data);
                break;
            case 3:
                printf("Liste actuelle : ");
                printList(head);
                break;
            case 4:
                freeList(&head);
                return 0;
            default:
                printf("Option invalide. Veuillez réessayer.\n");
        }
    }

    return 0;
}