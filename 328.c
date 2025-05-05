# include<stdio.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}node;

struct ListNode* oddEvenList(struct ListNode* head) {
    int o=0, e=0;
    node* temp=head;
    while (head!=NULL){
        if (head->val % 2 ==0) e++;
        else o++;
        head=head->next;
    }

    head=temp;
    temp=NULL;
    
    



    
    
}