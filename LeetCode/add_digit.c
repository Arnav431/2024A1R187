int addDigits(int x) {
    int s=0;
    while(x>0){
        s+=pow(x%10,2);
        x/=10;
        if(s>=10){
            s=addDigits(s);
        }
    }
    return s;
}