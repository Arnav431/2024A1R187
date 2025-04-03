#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100  

struct st {
    int data;
    struct st *nxt;
};

struct st* New_node(int d) {
    struct st* new = (struct st*)malloc(sizeof(struct st));
    if(new == NULL) {
        printf("Memory allocation Failed!\n");
        return NULL;
    }
    new->data = d;
    new->nxt = NULL;
    return new;
}

void push(struct st** st, int d) {
    struct st* new = New_node(d);
    if (new == NULL) return;
    new->nxt = *st;
    *st = new;
}

void pop(struct st** st) {
    if (*st == NULL) return;
    struct st* t = *st;
    *st = (*st)->nxt;
    free(t);
}

int evaluateInfix(char* exp) {
    struct st* values = NULL;
    struct st* ops = NULL;
    for (int i = 0; exp[i]; i++) {
        if (isdigit(exp[i])) {
            int val = 0;
            while (i < strlen(exp) && isdigit(exp[i])) {
                val = (val * 10) + (exp[i] - '0');
                i++;
            }
            push(&values, val);
            i--;
        } else if (exp[i] == '(') {
            push(&ops, exp[i]);
        } else if (exp[i] == ')') {
            while (ops != NULL && ops->data != '(') {
                if (values == NULL || (*values).nxt == NULL) { // Check for at least two operands
                    printf("Error: Invalid expression\n");
                    exit(1);
                }
                int val2 = values->data;
                pop(&values);
                int val1 = values->data;
                pop(&values);
                char op = (char)ops->data;
                pop(&ops);
                switch (op) {
                    case '+': push(&values, val1 + val2); break;
                    case '-': push(&values, val1 - val2); break;
                    case '*': push(&values, val1 * val2); break;
                    case '/': push(&values, val1 / val2); break;
                }
            }
            pop(&ops);
        } else if (exp[i] == '+' || exp[i] == '-' ||
                   exp[i] == '*' || exp[i] == '/') {
            while (ops != NULL && ops->data != '(') {
                if (values == NULL || (*values).nxt == NULL) {
                    printf("Error: Invalid expression\n");
                    exit(1);
                }
                int val2 = values->data;
                pop(&values);
                int val1 = values->data;
                pop(&values);
                char op = (char)ops->data;
                pop(&ops);
                switch (op) {
                    case '+': push(&values, val1 + val2); break;
                    case '-': push(&values, val1 - val2); break;
                    case '*': push(&values, val1 * val2); break;
                    case '/': push(&values, val1 / val2); break;
                }
            }
            push(&ops, exp[i]);
        }
    }
    while (ops != NULL) {
        if (values == NULL || (*values).nxt == NULL) {
            printf("Error: Invalid expression\n");
            exit(1);
        }
        int val2 = values->data;
        pop(&values);
        int val1 = values->data;
        pop(&values);
        char op = (char)ops->data;
        pop(&ops);
        switch (op) {
            case '+': push(&values, val1 + val2); break;
            case '-': push(&values, val1 - val2); break;
            case '*': push(&values, val1 * val2); break;
            case '/': push(&values, val1 / val2); break;
        }
    }
    if (values == NULL) {
        printf("Error: No result computed\n");
        exit(1);
    }
    int result = values->data;
    pop(&values);
    return result;
}

int evaluatePostfix(char* exp) {
    struct st* values = NULL;
    for (int i = 0; exp[i]; i++) {
        if (isdigit(exp[i])) {
            int val = 0;
            while (i < strlen(exp) && isdigit(exp[i])) {
                val = (val * 10) + (exp[i] - '0');
                i++;
            }
            push(&values, val);
            i--;
        } else if (exp[i] == ' ') {
            continue;
        } else if (exp[i] == '+' || exp[i] == '-' ||
                   exp[i] == '*' || exp[i] == '/') {
            if (values == NULL || (*values).nxt == NULL) {
                printf("Error: Invalid postfix expression\n");
                exit(1);
            }
            int val2 = values->data;
            pop(&values);
            int val1 = values->data;
            pop(&values);
            switch (exp[i]) {
                case '+': push(&values, val1 + val2); break;
                case '-': push(&values, val1 - val2); break;
                case '*': push(&values, val1 * val2); break;
                case '/': push(&values, val1 / val2); break;
            }
        }
    }
    if (values == NULL) {
        printf("Error: No result computed\n");
        exit(1);
    }
    int result = values->data;
    pop(&values);
    return result;
}

int evaluatePrefix(char* exp) {
    struct st* values = NULL;
    for (int i = strlen(exp) - 1; i >= 0; i--) {
        if (isdigit(exp[i])) {
            int val = 0, place = 1;
            while (i >= 0 && isdigit(exp[i])) {
                val = val + (exp[i] - '0') * place;
                place *= 10;
                i--;
            }
            push(&values, val);
            i++;
        } else if (exp[i] == ' ') {
            continue;
        } else if (exp[i] == '+' || exp[i] == '-' ||
                   exp[i] == '*' || exp[i] == '/') {
            if (values == NULL || (*values).nxt == NULL) {
                printf("Error: Invalid prefix expression\n");
                exit(1);
            }
            int val1 = values->data;
            pop(&values);
            int val2 = values->data;
            pop(&values);
            switch (exp[i]) {
                case '+': push(&values, val1 + val2); break;
                case '-': push(&values, val1 - val2); break;
                case '*': push(&values, val1 * val2); break;
                case '/': push(&values, val1 / val2); break;
            }
        }
    }
    if (values == NULL) {
        printf("Error: No result computed\n");
        exit(1);
    }
    int result = values->data;
    pop(&values);
    return result;
}

int main(){
    char exp[MAX];
    int x;
    printf("1. Infix\n2. Postfix\n3. Prefix\n4. Exit\n");
    while (1){
        printf("\nEnter cmd> ");
        scanf("%d", &x);
        getchar();
        switch (x)
        {
            case 1:
                printf("Enter an infix exp>\t");
                scanf(" %99[^\n]", exp);
                getchar();
                {
                    int result = evaluateInfix(exp);
                    printf("Infix Result>\t%d\n", result);
                }
                break;
            case 2:
                printf("Enter a postfix exp>\t");
                scanf(" %99[^\n]", exp);
                getchar();
                {
                    int result = evaluatePostfix(exp);
                    printf("Postfix Result>\t%d\n", result);
                }
                break;
            case 3:
                printf("Enter a prefix exp>\t");
                scanf(" %99[^\n]", exp);
                getchar();
                {
                    int result = evaluatePrefix(exp);
                    printf("Prefix Result>\t%d\n", result);
                }
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid command\n");
                break;
        }
    }
}