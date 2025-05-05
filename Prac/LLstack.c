#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

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

void push(struct Node** top, int d) {
    struct Node* new = newNode(d);
    if (new == NULL) return;
    new->next = *top;
    *top = new;
    printf("Pushed %d onto stack.\n", d);
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow! Stack is empty.\n");
        return -1;
    }
    struct Node* temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next;
    free(temp);
    printf("Popped %d from stack.\n", poppedData);
    return poppedData;
}

int peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}

int isEmpty(struct Node* top) {
    return top == NULL;
}

void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* stack = NULL;
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
