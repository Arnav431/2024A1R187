#include<stdio.h>
#include<stdlib.h>

/*
https://leetcode.com/problems/merge-k-sorted-lists/description/
*/

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* new_node(int d){
    struct ListNode* new = (struct ListNode *)malloc(sizeof(struct ListNode));
    new->val = d;
    new->next = NULL;
    return new;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

struct ListNode* mergeKLists(struct ListNode** lists, int s){
    int len = 0;
    for (int i = 0; i < s; i++) {
        struct ListNode* temp = lists[i];
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
    }

    struct ListNode* h = NULL;
    struct ListNode* t = NULL;

    int y = 0;

    int* l = (int*)malloc(len * sizeof(int));

    for (int i = 0; i < s; i++) {
        h = lists[i];
        while (h != NULL) {
            l[y++] = h->val;
            h = h->next;
        }
    }


    qsort(l, y, sizeof(int), compare);

    h = NULL;
    t = NULL;

    for (int i = 0; i < len; i++) {
        struct ListNode* temp = new_node(l[i]);
        if (h == NULL) {
            h = temp;
            t = h;
        } else {
            t->next = temp;
            t = t->next;
        }
    }

    free(l);
    return h;
}

int main(){
    struct ListNode* n1 = new_node(1);
    struct ListNode* n2 = new_node(4);
    struct ListNode* n3 = new_node(5);

    struct ListNode* n4 = new_node(1);
    struct ListNode* n5 = new_node(3);
    struct ListNode* n6 = new_node(4);

    struct ListNode* n7 = new_node(2);
    struct ListNode* n8 = new_node(6);

    n1->next = n2;
    n2->next = n3;

    n4->next = n5;
    n5->next = n6;

    n7->next = n8;

    struct ListNode* arr[3] = {n1, n4, n7};

    struct ListNode* ne = mergeKLists(arr, 3);

    while (ne != NULL) {
        printf("%d ", ne->val);
        ne = ne->next;
    }

    return 0;
}
