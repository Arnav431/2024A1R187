#include<stdio.h>

int main(){
    int l[4]={5,6,1,3};

    int temp;
    
    int y= sizeof(l)/sizeof(l[0]);
    for (int i=0;i<y-1; i++){
        for (int j=0; j< y-i;j++){
            if(l[j]>l[j+1]){
                temp=l[j];
                l[j]=l[j+1];
                l[j+1]=temp;
            }
        }
    }

    for (int i=0 ; i<y ; i++){
        printf("%d ", l[i]);
    }
    return 0;
}
