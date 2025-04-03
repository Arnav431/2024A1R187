# include<stdio.h>
# include<string.h>
# include<stdlib.h>
char * mergeAlternately(char * word1, char * word2){
    int l1=strlen(word1);
    int l2=strlen(word2);
    int l=l1+l2;
    char *res=(char*)malloc((l+1)*sizeof(char));
    int i = 0, j = 0, k = 0;
    
    while (i < l1 && j < l2) {
        res[k++] = word1[i++];
        res[k++] = word2[j++];
    }

    while (i < l1) {
        res[k++] = word1[i++];
    }

    while (j < l2) {
        res[k++] = word2[j++];
    }
    res[k] = '\0';

    return res;
}