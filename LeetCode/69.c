#include<stdio.h>
#include<math.h>

int mySqrt(int x) {
    return(pow(x,0.5));
}

int main(){
    printf("%d", mySqrt(8));
    return 0;

}
