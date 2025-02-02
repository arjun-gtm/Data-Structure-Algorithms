#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *first = NULL, *last = NULL;

void insertAtFirst(int);
void insertAtLast(int);
void insertAfterGivenNode(int, int);
void deleteFirstNode();
void deleteLastNode();
void displayList();

int main() {
    int choice, data, key;

    do {
        printf("\nEnter your choice:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert after a given node\n");
        printf("4. Delete first node\n");
        printf("5. Delete last node\n");
        printf("6. Display list\n");
        printf("7. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtFirst(data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtLast(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter data of the node after which to insert: ");
                scanf("%d", &key);
                insertAfterGivenNode(data, key);
                break;
            case 4:
                deleteFirstNode();
                break;
            case 5:
                deleteLastNode();
                break;
            case 6:
                displayList();
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}

//Function to display all the linked list items.
void displayList() {
    struct node *temp = first;

    if (first == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

//Function to insert a node at the beginning of linked list.
void insertAtFirst(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = first;

    if (first == NULL) {
        last = newNode;
    }

    first = newNode;
}

//Function to insert a node at the end of linked list.
void insertAtLast(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    if (first == NULL) {
        first = last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
}

//Function to insert a node after the given node of linked list.
void insertAfterGivenNode(int data, int key) {
    struct node *temp = first;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with key %d not found!\n", key);
        return;
    }

    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
}

//Function to delete the first node of the linked list.
void deleteFirstNode() {
    if (first == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }

    struct node *temp = first;
    first = first->next;
    free(temp);

    if (first == NULL) {
        last = NULL;
    }
}

//Function to delete the last node of the linked list.
void deleteLastNode() {
    if (first == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }

    if (first == last) {
        free(first);
        first = last = NULL;
        return;
    }

    struct node *temp = first;
    while (temp->next != last) {
        temp = temp->next;
    }

    free(last);
    last = temp;
    last->next = NULL;
}
