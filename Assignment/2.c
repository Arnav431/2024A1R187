//Develop a menu-driven program to implement a queue using a singly linked list. The program must allow the user to perform operations: Enqueue, Dequeue, Peek, and Display, based on user inputs.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int d;
    struct Node* nxt;
} node;

node* f = NULL;
node* r = NULL;

void enqueue(int d) {
    node* new = (node*)malloc(sizeof(node));
    if (new == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    new->d = d;
    new->nxt = NULL;
    
    if (r == NULL) {
        f = r = new;
    } else {
        r->nxt = new;
        r = new;
    }
    printf("%d enqueued to queue\n", d);
}

int dequeue() {
    if (f == NULL) {
        printf("Queue Underflow\n");
        return -1;
    }
    node* temp = f;
    int d = temp->d;
    f = f->nxt;
    if (f == NULL) r = NULL;
    free(temp);
    return d;
}

int peek() {
    if (f == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return f->d;
}

void display() {
    if (f == NULL) {
        printf("Queue is empty\n");
        return;
        }
    printf("Queue: [");
    node* temp = f;
    while (temp != NULL) {
        printf("%d", temp->d);
        temp = temp->nxt;
        if (temp != NULL) printf(", ");
    }
    printf("]\n");
}

int main() {
    int choice, val;
    
    printf("\n=== Queue Operations ===\n");
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                val = dequeue();
                if (val != -1)
                    printf("%d dequeued from queue\n", val);
                break;
            case 3:
                val = peek();
                if (val != -1)
                    printf("f element: %d\n", val);
                break;
            case 4:
                display();
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