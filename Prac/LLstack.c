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

void push(node** top, int d) {
    node* new = newNode(d);
    if (new == NULL) return;
    new->next = *top;
    *top = new;
    printf("Pushed %d onto stack.\n", d);
}

int pop(node** top) {
    if (*top == NULL) {
        printf("Stack underflow! Stack is empty.\n");
        return -1;
    }
    node* temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next;
    free(temp);
    printf("Popped %d from stack.\n", poppedData);
    return poppedData;
}

int peek(node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}

int isEmpty(node* top) {
    return top == NULL;
}

void display(node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node* stack = NULL;
    int choice, val;
    printf("1. Push\n2. Pop\n3. Peek\n4. Display Stack\n5. Exit\n");

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
                pop(&stack);
                break;
            case 3:
                val = peek(stack);
                if (val != -1)
                    printf("Top element is: %d\n", val);
                break;
            case 4:
                display(stack);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
