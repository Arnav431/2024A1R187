#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* new_node(int val) {
    struct ListNode* new=(struct ListNode*)malloc(sizeof(struct ListNode));
    if (!new) {
        printf("Memory allocation failed\n");
        return 0;
    }
    new->val = val;
    new->next = NULL;
    
    return new;
}

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* revh=NULL;
    struct ListNode* temp=head;

    while (temp!=NULL){
        struct ListNode* new = new_node(temp->val);
        new->next=revh;
        revh=new;
        temp=temp->next;
    }
    return revh;
}

int main() {
    struct ListNode* head = new_node(1);
    head->next = new_node(2);
    head->next->next = new_node(3);
    head->next->next->next = new_node(4);

    printf("Original List: ");
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }

    struct ListNode* revh = reverseList(head);
    printf("\nReversed List: ");
    temp = revh;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }

    return 0;
}
