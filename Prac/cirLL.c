#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

node* newNode(int d) {
    node* new = (node*)malloc(sizeof(node));
    if (new == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    new->data = d;
    new->next = NULL;
    return new;
}

void insert(node** head, int d) {
    node* new = newNode(d);
    if (new == NULL) return;

    if (*head == NULL) {
        new->next = new;
        *head = new;
    } else {
        node* temp = *head;
        while (temp->next != *head) temp = temp->next;
        temp->next = new;
        new->next = *head;
    }
    printf("%d Inserted.\n", d);
}

int search(node* head, int key) {
    if (head == NULL) return -1;
    node* temp = head;
    int pos = 0;
    do {
        if (temp->data == key) return pos;
        temp = temp->next;
        pos++;
    } while (temp != head);
    return -1;
}

void display(node* head) {
    if (head == NULL){ printf("List is empty.\n"); return;}
    node* temp = head;
    printf("Circular List: [");
    do {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != head) {
            printf(", ");
        }
    } while (temp != head);
    printf("]\n");
}

void deleteValue(node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* temp = *head;
    node* prev = NULL;

    if (temp->data == key) {
        if (temp->next == *head) {
            free(temp);
            *head = NULL;
        } else {
            while (temp->next != *head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            *head = temp->next;
            free(temp);
        }
        printf("Deleted %d from list.\n", key);
        return;
    }

    prev = temp;
    temp = temp->next;
    while (temp != *head && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == *head) {
        printf("Value %d not found.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from list.\n", key);
}


int main() {
    node* head = NULL;
    int choice, val, pos;
    printf("--- Menu ---\n");
    printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(&head, val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteValue(&head, val);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                pos = search(head, val);
                if (pos != -1)
                    printf("Value %d found at position %d.\n", val, pos);
                else
                    printf("Value %d not found in list.\n", val);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
