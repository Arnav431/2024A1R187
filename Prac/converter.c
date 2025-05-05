#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

char strStack[MAX][MAX];
int strTop = -1;


int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return -1;
}

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }
int isEmpty() { return top == -1; }

void pushStr(char *str) { strcpy(strStack[++strTop], str); }
char* popStr() { return strStack[strTop--]; }

void reverse(char str[]) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}

void swapParens(char expr[]) {
    int i;
    for (i = 0; expr[i]; i++) {
        if (expr[i] == '(') expr[i] = ')';
        else if (expr[i] == ')') expr[i] = '(';
    }
}


void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char c;
    top = -1;
    for (i = 0; infix[i]; i++) {
        c = infix[i];
        if (isalnum(c))
            postfix[k++] = c;
        else if (c == '(')
            push(c);
        else if (c == ')') {
            while (!isEmpty() && peek() != '(')
                postfix[k++] = pop();
            pop(); // remove '('
        }
        else if (isOperator(c)) {
            while (!isEmpty() && precedence(c) <= precedence(peek())) {
                if (c == '^' && peek() == '^') break; // right assoc
                postfix[k++] = pop();
            }
            push(c);
        }
    }
    while (!isEmpty())
        postfix[k++] = pop();
    postfix[k] = '\0';
}

void infixToPrefix(char infix[], char prefix[]) {
    char revInfix[MAX], postfix[MAX];
    strcpy(revInfix, infix);
    reverse(revInfix);
    swapParens(revInfix);
    infixToPostfix(revInfix, postfix);
    reverse(postfix);
    strcpy(prefix, postfix);
}

void postfixToInfix(char postfix[], char infix[]) {
    int i;
    char op1[MAX], op2[MAX], exp[MAX];
    strTop = -1; // reset string stack
    for (i = 0; postfix[i]; i++) {
        if (isalnum(postfix[i])) {
            char operand[2] = { postfix[i], '\0' };
            pushStr(operand);
        }
        else if (isOperator(postfix[i])) {
            strcpy(op2, popStr());
            strcpy(op1, popStr());
            sprintf(exp, "(%s%c%s)", op1, postfix[i], op2);
            pushStr(exp);
        }
    }
    strcpy(infix, popStr());
}

void prefixToInfix(char prefix[], char infix[]) {
    int i;
    char op1[MAX], op2[MAX], exp[MAX];
    strTop = -1;
    for (i = strlen(prefix) - 1; i >= 0; i--) {
        if (isalnum(prefix[i])) {
            char operand[2] = { prefix[i], '\0' };
            pushStr(operand);
        }
        else if (isOperator(prefix[i])) {
            strcpy(op1, popStr());
            strcpy(op2, popStr());
            sprintf(exp, "(%s%c%s)", op1, prefix[i], op2);
            pushStr(exp);
        }
    }
    strcpy(infix, popStr());
}

void postfixToPrefix(char postfix[], char prefix[]) {
    char infix[MAX];
    postfixToInfix(postfix, infix);
    infixToPrefix(infix, prefix);
}

void prefixToPostfix(char prefix[], char postfix[]) {
    char infix[MAX];
    prefixToInfix(prefix, infix);
    infixToPostfix(infix, postfix);
}

int main() {
    int choice;
    char input[MAX];
    char infix[MAX], postfix[MAX], prefix[MAX];

    printf("Choose input type:\n");
    printf("1. Infix\n");
    printf("2. Postfix\n");
    printf("3. Prefix\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &choice);

    printf("Enter expression: ");
    scanf("%s", input);

    switch (choice) {
        case 1:
            infixToPostfix(input, postfix);
            infixToPrefix(input, prefix);
            printf("\nPostfix: %s", postfix);
            printf("\nPrefix: %s\n", prefix);
            break;
        case 2:
            postfixToInfix(input, infix);
            infixToPrefix(infix, prefix);
            printf("\nInfix: %s", infix);
            printf("\nPrefix: %s\n", prefix);
            break;
        case 3:
            prefixToInfix(input, infix);
            infixToPostfix(infix, postfix);
            printf("\nInfix: %s", infix);
            printf("\nPostfix: %s\n", postfix);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
