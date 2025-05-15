#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int d;
    struct Node* nxt;
} node;

node* newNode(int d) {
    node* new = (node*)malloc(sizeof(node));
    if (new == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    new->d = d;
    new->nxt = NULL;
    return new;
}

void push(node** t, int d) {
    node* new = newNode(d);
    if (new == NULL) return;
    new->nxt = *t;
    *t = new;
    printf("%d pushed to stack\n", d);
}

int pop(node** t) {
    if (*t == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    node* temp = *t;
    int p = temp->d;
    *t = temp->nxt;
    free(temp);
    return p;
}

int peek(node* t) {
    if (t == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return t->d;
}

void display(node* t) {
    if (t == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: [");
    node* temp = t;
    while (temp != NULL) {
        printf("%d", temp->d);
        temp = temp->nxt;
        if (temp != NULL) printf(", ");
    }
    printf("]\n");
}

int main() {
    node* stack = NULL;
    int choice, val;
    
    printf("=== Stack Operations ===\n");
    printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(&stack, val);
                break;
            case 2:
                val = pop(&stack);
                if (val != -1)
                    printf("%d popped from stack\n", val);
                break;
            case 3:
                val = peek(stack);
                if (val != -1)
                    printf("Top element: %d\n", val);
                break;
            case 4:
                display(stack);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

