#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *last = NULL;

void insertAtBeginning(int);
void insertAtEnd(int);
void insertAfterGivenNode(int, int);
void deleteFirstNode();
void deleteLastNode();
void displayList();

int main() {
    int choice, data, key;

    do {
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert after a given node\n");
        printf("4. Delete first node\n");
        printf("5. Delete last node\n");
        printf("6. Display list\n");
        printf("7. Exit\n");
        
        printf("\nEnter your choice:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(data);
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
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}

void displayList() {
    if (last == NULL) {
        printf("Circular linked list is empty!\n");
        return;
    }

    struct node *temp = last->next;
    printf("Circular linked list: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

void insertAtBeginning(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
}

void insertAtEnd(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void insertAfterGivenNode(int data, int key) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = last->next;
    do {
        if (temp->data == key) {
            struct node *newNode = (struct node*)malloc(sizeof(struct node));
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
            if (temp == last) {
                last = newNode;
            }
            return;
        }
        temp = temp->next;
    } while (temp != last->next);

    printf("Node with key %d not found!\n", key);
}

void deleteFirstNode() {
    if (last == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }

    struct node *temp = last->next;
    if (last == temp) {
        last = NULL;
    } else {
        last->next = temp->next;
    }
    free(temp);
}

void deleteLastNode() {
    if (last == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }

    struct node *temp = last->next;
    if (last == temp) {
        free(last);
        last = NULL;
    } else {
        while (temp->next != last) {
            temp = temp->next;
        }
        temp->next = last->next;
        free(last);
        last = temp;
    }
}

