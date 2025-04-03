#include<stdio.h>
#define MAX_SIZE 100

void display(int arr[],int *size){
        printf("list=[");
        for (int i=0;i<*size;i++){
                printf("%d, ",arr[i]);
        }
        printf("\b\b]");
}


void Insert(int arr[],int* size){
        int x,y;
        printf("Enter the number and index to be inserted>\t");
        scanf("%d %d", &x,&y);
        if (*size>=MAX_SIZE) {
                printf("Array is full! Cannot insert.\n");
                return;
        }
        else if(y<0 || y>*size){
                printf("Invalid index!\n");
                return;
        }
        else if(y==*size){
               arr[*size]=x;
               (*size)++;
        }
        else{
                for (int i=*size;i>y;i--){
                        arr[i]=arr[i-1];
                }
                arr[y]=x;
                (*size)++;
        }
}


void Search(int arr[],int* size){
        int x, flag=0,i;
        printf("Enter the element to be Searched>\t");
        scanf("%d",&x);
        for(i=0;i<*size;i++){
                if (arr[i]==x){
                        flag=1;
                        break;
                }else{
                        flag=0;
                }
        }
        if (flag==1){
                printf("Element '%d' found on index %d in the array.\n",x,i);
        }else{
                printf("Element not found!\n");
        }
}


void Delete(int arr[],int* size){
        int x,index,flag=1;
        printf("Enter the element to be deleted>\t");
        scanf("%d",&x);
        for(int i=0;i<*size;i++){
                if (arr[i]==x){
                        index=i;
                        flag=1;
                        break;
                }
                else{
                        flag=0;
                }
        }
        if (flag==1){
                for(int i=index;i<*size;i++){
                        arr[i]=arr[i+1];
                }
                (*size)--;
        }else{
                printf("Element not found!");
        }
}


int main(){
        int l,c,arr[MAX_SIZE];
        printf("Input Length of Array>\t");
        scanf("%d",&l);
        printf("Enter elements>");

        for (int i=0; i<l;i++){
                scanf("%d",&arr[i]);
        }
        while(1){
                printf("\nMenue:\n\t1. Insert\n\t2. Delete\n\t3. Search\n\t4. Display\n\t5. Exit");
                printf("\nEnter Choice>\t");
                scanf("%d",&c);
                switch (c)
                {
                case 1:
                        Insert(arr,&l);
                        break;
                case 2:
                        Delete(arr,&l);
                        break;
                case 3:
                        Search(arr,&l);
                        break;
                case 4:
                        display(arr,&l);
                        break;
                case 5:
                        printf("Bye-Bye");
                        return 0;
                        break;
                default:
                        printf("Enter the choice carefully");
                        break;
                }
        }
}