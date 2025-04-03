#include <limits.h>

int reverse(int x){
    
    long r,s=0;

    while(x!=0){
        r=x%10;
        s=s*10+r;
        x/=10;
    }
    if (s>INT_MAX || s<INT_MIN){
        s=0;  
    }
    return s;
}