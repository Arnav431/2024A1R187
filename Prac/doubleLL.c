#include<stdio.h>
#include<stdlib.h>

struct dLL{
    struct dLL* pre;
    int data;
    struct dLL* nxt;
};


struct dLL* New_node(int d){
    struct dLL* new=(struct dLL*)malloc(sizeof(struct dLL));
    if(new==NULL){
        printf("Memmory allocation Failed!");
        return new;
    }
    new->pre=NULL;
    new->data=d;
    new->nxt=NULL;
    return new;
} 
void atbeg(struct dLL **st, int d){
    struct dLL* new=New_node(d);
    if (new==NULL) return;
    new->nxt=*st;
    (*st)->pre=new; 
    *st=new; 
}

void printList(struct dLL* h) {
    struct dLL* temp = h;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->nxt;
    }
    printf("\n");
}

void atend(struct dLL** l,int d){
    struct dLL* new=New_node(d);
    if (new==NULL) return;
    (*l)->nxt=new;
    new->pre=*l;       
}

void after(struct dLL** l, int d){
    struct dLL* new=New_node(d);
    if (new==NULL) return;
    new->nxt=(*l)->nxt;
    new->pre=*l;
    (*l)->nxt=new;
}

void before(struct dLL** l, int d){
    struct dLL* new=New_node(d);
    if (new==NULL) return;
    new->nxt=*l;


         

}


int main(){
    struct dLL* head=New_node(1);
    struct dLL* mid=New_node(2);
    struct dLL* end=New_node(3); 

    struct dLL *st;
    st->nxt=head;

    head->nxt=mid;
    mid->pre=head;
    mid->nxt=end;
    end->pre=mid;

    printList(st->nxt);
}



