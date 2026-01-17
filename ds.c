#include <stdio.h>
#include <stdlib.h>

/* Structure for linked list node */
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Function to create linked list */
void create() {
    int n, i, value;
    struct node *temp = NULL, *newnode = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));

        if (newnode == NULL) {
            printf("failed\n");
            return;
        }

        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}

/* Function to insert at beginning */
void insert_beg() {
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter value to insert at beginning: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}

/* Function to display linked list */
void display() {
    struct node *temp;

    if (head == NULL) {
        printf("Linked list is empty!!\n");
        return;
    }

    temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Function to delete node at end */
void delete_end() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty... Nothing to delete\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted\n");
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    printf("Last node deleted\n");
}

/* Main function */
int main() {
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Display List\n");
        printf("4. Delete at End\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;

            case 2:
                printf("\nBefore Insertion:\n");
                display();
                insert_beg();
                printf("\nAfter Insertion:\n");
                display();
                break;

            case 3:
                display();
                break;

            case 4:
                delete_end();
                break;

            case 5:
                printf("Program exited\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
