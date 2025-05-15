#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int d;
    struct Node *l, *r;
} node;

node* newNode(int d) {
    node* temp = (node*)malloc(sizeof(node));
    temp->d = d;
    temp->l = temp->r = NULL;
    return temp;
}

node* insert(node* root, int d) {
    if (root == NULL) return newNode(d);
    
    if (d < root->d)
        root->l = insert(root->l, d);
    else if (d > root->d)
        root->r = insert(root->r, d);
    
    return root;
}

node* minValueNode(node* node) {
    struct Node* current = node;
    while (current && current->l != NULL)
        current = current->l;
    return current;
}

node* deleteNode(node* root, int key) {
    if (root == NULL) return root;

    if (key < root->d)
        root->l = deleteNode(root->l, key);
    else if (key > root->d)
        root->r = deleteNode(root->r, key);
    else {
        if (root->l == NULL) {
            node* temp = root->r;
            free(root);
            return temp;
        } else if (root->r == NULL) {
            node* temp = root->l;
            free(root);
            return temp;
        }
        
        node* temp = minValueNode(root->r);
        root->d = temp->d;
        root->r = deleteNode(root->r, temp->d);
    }
    return root;
}

void inorder(node* root) {
    if (root != NULL) {
        inorder(root->l);
        printf("%d ", root->d);
        inorder(root->r);
    }
}

int main() {
    node* root = NULL;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nInorder traversal: ");
    inorder(root);

    printf("\nEnter value to delete: ");
    scanf("%d", &val);
    root = deleteNode(root, val);

    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}