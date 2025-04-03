#include <stdio.h>
#include <string.h>


int lengthOfLongestSubstring(char *s) {
    int i[256];  
    memset(i, -1, sizeof(i));  
    
    int ml = 0, st = 0;

    for (int e = 0; s[e] != '\0'; e++) {
        if (i[s[e]] >= st) {
            st = i[s[e]] + 1;
        }
        i[s[e]] = e;
        int cl = e - st + 1;
        if (cl > ml) {
            ml = cl;
        }
    }
    
    return ml;
}