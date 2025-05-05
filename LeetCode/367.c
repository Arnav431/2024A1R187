#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool isPerfectSquare(int num) {
    int x = (int)sqrt((double)num);
    return x*x==num;
}

int main(){
    printf("%d",isPerfectSquare(5));
    return 0;
}