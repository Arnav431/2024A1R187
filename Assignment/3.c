#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int d;
    struct Node* pre;
    struct Node* nxt;
} node;

void insertSorted(node** head, int d) {
    node* new = (node*)malloc(sizeof(node));
    new->d = d;
    new->pre = NULL;
    new->nxt = NULL;

    if (*head == NULL) {
        *head = new;
        return;
    }

    if (d <= (*head)->d) {
        new->nxt = *head;
        (*head)->pre = new;
        *head = new;
        return;
    }

    node* c = *head;
    while (c->nxt != NULL && c->nxt->d < d) {
        c = c->nxt;
    }

    new->nxt = c->nxt;
    new->pre = c;
    if (c->nxt != NULL) {
        c->nxt->pre = new;
    }
    c->nxt = new;
}

node* mergeLists(node* f, node* s) {
    if (!f) return s;
    if (!s) return f;

    node* merged = NULL;
    node* temp;

    while (f && s) {
        if (f->d <= s->d) {
            temp = f;
            f = f->nxt;
        } else {
            temp = s;
            s = s->nxt;
        }
        insertSorted(&merged, temp->d);
    }

    while (f) {
        insertSorted(&merged, f->d);
        f = f->nxt;
    }

    while (s) {
        insertSorted(&merged, s->d);
        s = s->nxt;
    }

    return merged;
}

void display(node* head) {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    printf("List: [");
    node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->d);
        temp = temp->nxt;
        if (temp != NULL) printf(", ");
    }
    printf("]\n");
}

int main() {
    node *list1 = NULL, *list2 = NULL;
    int n1, n2, val;

    printf("Enter number of elements for first list: ");
    scanf("%d", &n1);
    printf("Enter elements for first list:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        insertSorted(&list1, val);
    }

    printf("Enter number of elements for second list: ");
    scanf("%d", &n2);
    printf("Enter elements for second list:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        insertSorted(&list2, val);
    }

    printf("\nFirst ");
    display(list1);
    printf("Second ");
    display(list2);

    node* merged = mergeLists(list1, list2);
    printf("Merged ");
    display(merged);

    return 0;
}
