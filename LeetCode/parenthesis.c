#include <stdbool.h>
bool isValid(char* s) {
    int len = strlen(s);
    char stack[len];  
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        }
        else {
            if (top == -1) {
                return 0; 
            }

            char topChar = stack[top]; 

            if ((c == ')' && topChar != '(') || 
                (c == '}' && topChar != '{') || 
                (c == ']' && topChar != '[')) {
                return 0;
            }

            top--; 
        }
    }
    if(top == -1) return 1;
    else return 0;
}