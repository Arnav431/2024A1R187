#include<stdio.h>

int findNumbers(int* nums, int numsSize) {
    int c=0,co;
    for(int i=0; i<numsSize; i++){
        co=0;
        while (nums[i]>0){
            nums[i]=nums[i]/10;
            co++;
        }
        if(co%2==0){
            c++;
        }
    }
    return c;
}

int main(){
    int l[5]={12,345,2,6,7896};
    int x=findNumbers(l,5);
    printf("%d",x);
    return 0;
}