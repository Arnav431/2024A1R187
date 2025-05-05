#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool isUgly(int n) {
    
}

int* primeFactorizer(int n){
    int* l=(int)malloc(n*sizeof(int));
    int y=0;
    while(!isPrime(n)){
        for(int i=2;i<(n/2);i++){
            if(isPrime(i) && n%i==0){
                n=n/i;
                l[y++]=i;
            }
        }
        

    }


}

bool isPrime(int n){
    for(int i=0;i<(n/2);i++){
        if (n%i==0) return false;
    }
    return true;
}
