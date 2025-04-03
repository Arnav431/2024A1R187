#include<stdio.h>
#define s 5
int queue[s]={1,2,3,4,5};
int f=-1,r=-1;


void Enqueue(){
        int x;
        printf("Enter the element to be inserted>\t\n");
        scanf("%d",&x);
        if (r==s-1){
                printf("Queue is full\n");
        }
        if(f==-1){
                f=0;
        }
        r++;
        queue[r]=x;
        printf("%d imserted in the queue\n",x);
}


void Dequeue(){
        if (f==-1){
                printf("Queue is empty\n");
        }else{
                printf("Dequeued %d from the queue",queue[f]);
                f++;
        }
}

void Display(){
        if (f==-1){
                printf("Queue is empty\n");
        }else{
                printf("Queue elements are:\t(");
                for(int i=0;i<=r;i++){
                        printf("%d, ",queue[i]);
                }
                printf("\b\b)");
        }

}

int main(){
        int c;
        while(1){
                printf("\nMenue:\n\t1. Enqueue\n\t2. Dequeue\n\t3. Display\n\t4. Exit\n\t");
                printf("\nEnter Choice>\t");
                scanf("%d",&c);
                switch (c)
                {
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
                        printf("Bye-Bye");
                        return 0;
                        break;
                default:
                        printf("Enter the choice carefully");
                        break;
                }
        }
}