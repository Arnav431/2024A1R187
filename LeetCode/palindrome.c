#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool isPalindrome(int x) {
    long r,s=0;
    int y=x;
    if (x<0){
        return false;
    }else{
        while(x!=0){
            r=x%10;
            s=s*10+r;
            x/=10;
        }

        if (y==s){
            return true;
        }else{
            return false;
        }
    }
}
