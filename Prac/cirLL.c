#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* newNode(int d) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    if (new == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    new->data = d;
    new->next = NULL;
    return new;
}

// Insert after a given node
void insertAfter(struct Node* head, int key, int d) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        if (temp->data == key) {
            struct Node* new = newNode(d);
            if (new == NULL) return;

            new->next = temp->next;
            temp->next = new;
            printf("Inserted %d after %d.\n", d, key);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Value %d not found in list.\n", key);
}

// Delete by value
void deleteValue(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If head node itself holds the key
    if (temp->data == key) {
        if (temp->next == *head) { // Only one node
            free(temp);
            *head = NULL;
        } else {
            while (temp->next != *head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            *head = temp->next;  // New head
            free(temp);
        }
        printf("Deleted %d from list.\n", key);
        return;
    }

    // Search for the node to delete
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

// Search
int search(struct Node* head, int key) {
    if (head == NULL) return -1;
    struct Node* temp = head;
    int pos = 0;
    do {
        if (temp->data == key) return pos;
        temp = temp->next;
        pos++;
    } while (temp != head);
    return -1;
}

// Display list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// MAIN
int main() {
    struct Node* head = NULL;
    int choice, val, key, pos;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert after a value\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert after: ");
                scanf("%d", &key);
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertAfter(head, key, val);
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
