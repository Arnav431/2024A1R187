int kthFactor(int n, int k) {
    int j=0;
    int *l=(int *)malloc(100*4);
    for (int i=1;i<=(n/2);i++){
        if(n%i==0){
            l[j++]=i;
        }
    }
    l[j++]=n;
    if(j<k){
        return -1;
    }
    return l[k-1];
}