#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

void inordIterative(struct node*root){
    struct stack{
        int top;
        struct node* item[1000];
    } s;
    struct node* p;
    s.top = -1;
    p = root;
    do{
        while (p != 0){
            s.top++;
            s.item[s.top] = p;
            p = p -> left;
        }
        if (s.top != -1){
            p = s.item[s.top];
            s.top--;
            printf("%d ", p -> data);
            p = p -> right;
        }
    } while (p != 0 || s.top != -1);
}
void preordIterative(struct node* root){
    struct stack{
        int top;
        struct node* item[1000];
    } s;
    struct node* p;
    s.top = -1;
    p = root;
    s.top++;
    s.item[s.top] = p; 
    while (s.top != -1){
        p = s.item[s.top];
        s.top--;
        printf("%d ", p->data);
        if (p->right != 0){
            s.top++;
            s.item[s.top] = p->right;
        }
        if (p -> left != 0){
            s.top++;
            s.item[s.top] = p->left;
        }
        p = p -> left;
    }
}
struct node *create(){
    int x ;
    struct node* newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
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

int main(){
    struct node* root = 0;
    // root = 0 ;
    root = create();
    printf("Inorder Traversal \n");
    inordIterative(root);
    printf("\nPreorder Traversal \n");
    preordIterative(root);
    return 0;
}

