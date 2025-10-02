#include <stdio.h>
#include <stdlib.h>

// Structure pour représenter un nœud de la liste
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour créer un nouveau nœud
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d'allocation de mémoire\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fonction pour insérer un nœud à la fin de la liste
void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fonction pour supprimer les occurrences d'un nombre dans la liste
void supprimer_occurences(Node** head, int nombre) {
    Node* temp = *head;
    Node* prev = NULL;

    while (temp) {
        if (temp->data == nombre) {
            if (prev == NULL) {
                *head = temp->next;
                free(temp);
                temp = *head;
            } else {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

// Fonction pour afficher la liste
void afficherListe(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int nombre, choix;

    printf("Entrez le nombre d'éléments de la liste : ");
    scanf("%d", &choix);

    for (int i = 0; i < choix; i++) {
        printf("Entrez l'élément %d : ", i + 1);
        scanf("%d", &nombre);
        insertNode(&head, nombre);
    }

    printf("Liste originale : ");
    afficherListe(head);

    printf("Entrez le nombre à supprimer : ");
    scanf("%d", &nombre);

    supprimer_occurences(&head, nombre);

    printf("Liste après suppression des occurrences de %d : ", nombre);
    afficherListe(head);

    return 0;
}