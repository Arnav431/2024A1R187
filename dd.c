#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode{
    int val;
    struct ListNode* pre;
    struct ListNode* nxt;
}node;

node* newNode(int data, node* pre){
    node* new=(node*)malloc(sizeof(node));
    new->val=data;
    new->pre=pre;
    new->nxt=NULL;
    return new;
} 


int main(){
    int n,a,s,x=0;
    node* h=NULL;
    node* t=NULL;

    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(h==NULL){
            h=newNode(a,NULL);
            t=h;
        }else{
            t->nxt=newNode(a,t);
            t=t->nxt;
        }
    }
    scanf("%d",&s);

    while(h!=NULL){
        if (h->val==s){
            printf("Found");
            return 0;
        }
        h=h->nxt;
    }
    printf("Not Found");
    return 0;
}