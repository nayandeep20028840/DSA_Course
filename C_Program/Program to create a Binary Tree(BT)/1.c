#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node *create(){
    int x ;
    struct node* newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    printf("Enter data to be stored : ");
    scanf("%d" , &x);
    if(x == -1){
        return 0;
    }
    newnode -> data = x;
    printf("Enter left child %d " , x);
    newnode -> left = create();
    printf("Enter right child %d " , x);
    newnode -> right = create();
}

void printTree(struct node* root){
    if(root == NULL){
        return ;
    }
    if(root -> left){
        printf("%d " , root -> left -> data);
    }
    if(root -> right){
        printf("%d " , root -> right -> data);
    }
    // printf("\n");
    printTree(root -> left) ;
    printTree(root -> right) ;
}

int main(){
    struct node*root;
    root = 0 ;
    root = create();
    printf("%d " , root -> data);
    printTree(root);
    return 0;
}

