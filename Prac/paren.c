#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

int is_matching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int is_balanced(char expr[]) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            char popped = pop();
            if (popped == '\0' || !is_matching(popped, c)) {
                return 0;
            }
        }
    }
    return top == -1;
}

int main() {
    char expr[100];
    printf("Enter an expression: ");
    scanf("%s", expr);
    if (is_balanced(expr))
        printf("Expression is balanced.\n");
    else
        printf("Expression is NOT balanced.\n");
    return 0;
}