#include<stdio.h>
#include<stdlib.h>

/*
https://leetcode.com/problems/merge-k-sorted-lists/description/
*/

typedef struct ListNode {
    int val;
    struct node *next;
}node;

node* new_node(int d){
    node* new=(node *)malloc(sizeof(node));
    new->val=d;
    new->next=NULL;
    return new;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

node* mergeKLists(node** lists, int s){


    int len = 0;
    for (int i = 0; i < s; i++) {
        node* temp = lists[i];
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
    }

    node* h=new_node(NULL);
    node* t=new_node(NULL);

    int y=0;

    int l[]=(int*)malloc(len*sizeof(int));

    for(int i=0; i<s; i++){
        h=lists[i];
        while (h!=NULL){
            l[y++]=h->val;
            h=h->next;
        }
        
    }
    qsort(l, y, sizeof(int), compare);

    for (int i = 0; i < len; i++) {
        node* temp = new_node(l[i]);
        if (h==NULL){
            h==temp;
            t=h;
        }else{
            t->next=temp;
            t=t->next;
        }
    }
    free(l);
    return h;
}


int main(){

    node* n1=new_node(1);
    node* n2=new_node(4);
    node* n3=new_node(5);


    node* n4=new_node(1);
    node* n5=new_node(3);
    node* n6=new_node(4);


    node* n7=new_node(2);
    node* n8=new_node(6);
    

    n1->next=n2;
    n2->next=n3;

    n4->next=n5;
    n5->next=n6;

    n7->next=n8;

    node arr[3]={n1,n4,n7};

    node* ne=mergeKLists(arr,3);
    
    while(ne!=NULL){
        printf("%d ", ne->val);
        ne=ne->next;
    }

    return 0;
}