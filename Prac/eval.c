#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define N 100

int s[N], t = -1;

void push(int x) {
    if (t == N - 1) {
        printf("Overflow\n");
        exit(1);
    }
    s[++t] = x;
}

int pop() {
    if (t == -1) {
        printf("Underflow\n");
        exit(1);
    }
    return s[t--];
}

int is_op(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int calc(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    if (op == '^') return pow(a, b);
    return 0;
}

int eval_post(char e[]) {
    for (int i = 0; e[i]; i++) {
        char c = e[i];
        if (isdigit(c)) {
            push(c - '0');
        } else if (is_op(c)) {
            int b = pop(), a = pop();
            push(calc(a, b, c));
        } else if (c == ' ') {
            continue;  // Skip spaces
        }
    }
    return pop();
}

int eval_pre(char e[]) {
    int len = strlen(e);
    for (int i = len - 1; i >= 0; i--) {
        char c = e[i];
        if (isdigit(c)) {
            push(c - '0');
        } else if (is_op(c)) {
            int a = pop(), b = pop();
            push(calc(a, b, c));
        } else if (c == ' ') {
            continue;  // Skip spaces
        }
    }
    return pop();
}

void in_to_post(char in[], char out[]) {
    char st[N];
    int top = -1, j = 0;
    for (int i = 0; in[i]; i++) {
        char c = in[i];
        if (isdigit(c)) out[j++] = c;
        else if (c == '(') st[++top] = c;
        else if (c == ')') {
            while (top != -1 && st[top] != '(') out[j++] = st[top--];
            if (top != -1 && st[top] == '(') top--;
        } else if (is_op(c)) {
            while (top != -1 && prec(st[top]) >= prec(c)) out[j++] = st[top--];
            st[++top] = c;
        }
    }
    while (top != -1) out[j++] = st[top--];
    out[j] = '\0';
}

int eval_in(char e[]) {
    char post[N];
    in_to_post(e, post);
    return eval_post(post);
}

int main() {
    char exp[N];
    int ch;
    printf("1. Postfix\n2. Prefix\n3. Infix\n4. Exit.");
    while (1) {
        printf("\nChoice: ");
        scanf("%d", &ch);
        if (ch == 4) return 0; 
        printf("Expr: ");
        scanf("%s", exp);

        if (ch == 1) printf("Result: %d\n", eval_post(exp));
        else if (ch == 2) printf("Result: %d\n", eval_pre(exp));
        else if (ch == 3) printf("Result: %d\n", eval_in(exp));
        else printf("Invalid\n");
    }
}

