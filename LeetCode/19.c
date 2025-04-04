#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


int counter(struct ListNode* head){
    int c=0;
    while(head!=NULL){
        c++;
        head=head->next;
    }
    return c;
}


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* temp=head;
    int c=counter(head);

    if(c==1 && n==1) return NULL;

    if(c==n) return head->next;
    
    int i=0;
    
    for  (i=0;i<(c-n-1);i++) {
        temp=temp->next;
    }
    
    struct ListNode* del=temp->next;
    
    temp->next = del->next;
    
    free(del);
    return head;
    
}




struct ListNode* New_node(int d){
    struct ListNode* new=(struct ListNode*)malloc(sizeof(struct ListNode));
    if(new==NULL){
        printf("Memmory allocation Failed!");
        return new;
    }
    new->val=d;
    new->next=NULL;
    return new;
} 

int main(){
    struct ListNode* head=New_node(1);
    struct ListNode* second=New_node(2);
    struct ListNode* third=New_node(3);
    struct ListNode* fourth=New_node(4);
    struct ListNode* fifth=New_node(5);

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;

    int n=2;
    
    head=removeNthFromEnd(head,n);
    
    while(head!=NULL){
        printf("%d ",head->val);
        head=head->next;
    }
    
    return 0;

}