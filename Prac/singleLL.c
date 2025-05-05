#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* nxt;
} node;

node* newNode(int d) {
    node* new = (node*)malloc(sizeof(node));
    new->val = d;
    new->nxt = NULL;
    return new;
}


void insertEnd(node** head, int d) {
    node* temp = newNode(d);
    if (*head == NULL) {
        *head = temp;
        return;
    }
    node* curr = *head;
    while (curr->nxt != NULL) {
        curr = curr->nxt;
    }
    curr->nxt = temp;
}


void deleteValue(node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node* temp = *head;
    if (temp->val == key) {
        *head = temp->nxt;
        free(temp);
        printf("Deleted %d from list.\n", key);
        return;
    }
    node* prev = NULL;
    while (temp != NULL && temp->val != key) {
        prev = temp;
        temp = temp->nxt;
    }
    if (temp == NULL) {
        printf("Value %d not found.\n", key);
        return;
    }
    prev->nxt = temp->nxt;
    free(temp);
    printf("Deleted %d from list.\n", key);
}


int search(node* head, int key) {
    int pos = 0;
    while (head != NULL) {
        if (head->val == key) return pos;
        head = head->nxt;
        pos++;
    }
    return -1;
}


void display(node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->nxt;
    }
    printf("NULL\n");
}


int main() {
    node* head = NULL;
    int choice, val, pos;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertEnd(&head, val);
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