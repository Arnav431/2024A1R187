#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int f = -1, r = -1;


void Enqueue() {
    int x;
    if (r== SIZE-1) {
        printf("Queue is full!\n");
        return;
    }else{
        printf("Enter the element to be inserted>\t");
        scanf("%d", &x);
        if (f == -1) f = 0; 
        r++;
        queue[r]=x;
        printf("%d inserted into the queue.\n",x);
    }
}


void Dequeue() {
    if(f == -1 || f > r){ 
        printf("Queue is empty!\n");
        return;
    }else{
        printf("Dequeued %d from the queue.\n", queue[f]);
        f++;
        if (f > r) {
                f = -1;
                r = -1;
        }
    }  
}


void Display() {
    if (f==-1 || f>r){
        printf("Queue is empty!\n");
        return;
    }else{
        printf("Queue elements : ");
        for (int i = f; i <= r; i++) {
                printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    printf("\nMenue:\n\t1. Enqueue\n\t2. Dequeue\n\t3. Display\n\t4. Exit\n");
    while (1) {
        
        printf("\nEnter Choice>\t");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Enqueue();
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Display();
                break;
            case 4:
                printf("Bye-Bye\n");
                return 0;
            default:
                printf("Enter the choice carefully");
        }
    }
}
