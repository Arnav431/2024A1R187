#include <stdio.h>
#include <stdlib.h>

struct dLL {
    struct dLL* pre;
    int data;
    struct dLL* nxt;
};

// Create a new node
struct dLL* New_node(int d) {
    struct dLL* new = (struct dLL*)malloc(sizeof(struct dLL));
    if (new == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    new->pre = NULL;
    new->data = d;
    new->nxt = NULL;
    return new;
}

// Insert at end
void insert(struct dLL** head, int d) {
    struct dLL* new = New_node(d);
    if (new == NULL) return;
    if (*head == NULL) {
        *head = new;
        return;
    }
    struct dLL* temp = *head;
    while (temp->nxt != NULL)
        temp = temp->nxt;
    temp->nxt = new;
    new->pre = temp;
}

// Delete by value
void deleteValue(struct dLL** head, int key) {
    struct dLL* temp = *head;
    while (temp != NULL && temp->data != key)
        temp = temp->nxt;
    if (temp == NULL) {
        printf("Value %d not found.\n", key);
        return;
    }
    if (temp->pre != NULL)
        temp->pre->nxt = temp->nxt;
    else
        *head = temp->nxt;  // deleting head
    if (temp->nxt != NULL)
        temp->nxt->pre = temp->pre;
    free(temp);
    printf("Deleted %d from list.\n", key);
}

// Search
int search(struct dLL* head, int key) {
    int pos = 0;
    while (head != NULL) {
        if (head->data == key) return pos;
        head = head->nxt;
        pos++;
    }
    return -1;
}

// Display list
void display(struct dLL* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->nxt;
    }
    printf("\n");
}

int main() {
    struct dLL* head = NULL;
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