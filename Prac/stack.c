#include<stdio.h>
#define MAX_LEN 100

void isEmpty(int st[],int *size){
        if(*size == 0 && st[0]==-1){
                printf("Stack is empty\n");
        }else{
                printf("Stack is in use\n");
        }
}
void isFull(int st[],int *size){
        if(*size == MAX_LEN){
                printf("Stack is full\n");
        }else{
                printf("Stack can be used\n");
        }
}
void display(int st[],int *size){
        if(*size == 0){
                printf("Stack is empty\n");
        }else{
                printf("Stack=(");
                for (int i=0;i<*size;i++){
                        printf("%d, ",st[i]);
                }
                printf("\b\b)");
        }
}

void Push(int st[], int* size){
        int x;
        if(*size == MAX_LEN){
                printf("Stack is full\n");
        }else{
                printf("Enter element to be pushed in stack>\t");
                scanf("%d",&x);
                st[*size]=x;
                (*size)++;
        }
}

void Pop(int st[],int* size){
        if(*size == 0){
                printf("Stack is empty\n");
        }else{
                printf("Element Popped\n");
                (*size)--;
        }

}
void Peek(int st[],int* size){
        if(*size == 0){
                printf("Stack is empty\n");
        }else{
                printf("Top element is %d\n",st[*size-1]);
        }
}

int main(){
        int l,c,st[MAX_LEN]={-1};
        printf("Input Size of Stack>\t");
        scanf("%d",&l);
        printf("Enter elements>");

        for (int i=0; i<l;i++){
                scanf("%d",&st[i]);
        }
        while(1){
                printf("\nMenue:\n\t1. Push\n\t2. Pop\n\t3. Peek\n\t4. Display\n\t5. isFull\n\t6. isEmpty\n\t7. Exit");
                printf("\nEnter Choice>\t");
                scanf("%d",&c);
                switch (c)
                {
                case 1:
                        Push(st,&l);
                        break;
                case 2:
                        Pop(st,&l);
                        break;
                case 3:
                        Peek(st,&l);
                        break;
                case 4:
                        display(st,&l);
                        break;
                case 5:
                        isFull(st,&l);
                        break;
                case 6:
                        isEmpty(st,&l);
                        break;
                case 7:
                        printf("Bye-Bye");
                        return 0;
                        break;
                default:
                        printf("Enter the choice carefully");
                        break;
                }
        }
}