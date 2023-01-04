#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *left_child, *right_child;
};

struct node *new_node(int value){
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp -> value = value;
    tmp -> left_child = NULL;
    tmp -> right_child = NULL;
    return tmp;
}

struct node* insert_node(struct node* node, int value){ // inserting nodes!
    if (node == NULL) return new_node(value);
    if (value < node -> value){
        node -> left_child = insert_node(node -> left_child , value);
    }
    else if (value > node -> value){
        node -> right_child = insert_node(node -> right_child , value);
    }
    return node;
}

void printPreOrder(struct node* NODE){
    if(NODE == NULL) return;
    printf("%d " , NODE -> value);
    printPreOrder(NODE -> left_child);
    printPreOrder(NODE -> right_child);
}

void printInOrder(struct node* NODE){
    if(NODE == NULL) return;
    printInOrder(NODE -> left_child);
    printf("%d " , NODE -> value);
    printInOrder(NODE -> right_child);
}

void printPostOrder(struct node* NODE){
    if(NODE == NULL) return;
    printPostOrder(NODE -> left_child);
    printPostOrder(NODE -> right_child);
    printf("%d " , NODE -> value);
}

void print(struct node *root_node){ // displaying the nodes!
    if (root_node != NULL){
        print(root_node -> left_child);
        printf("%d ", root_node -> value);
        print(root_node -> right_child);
    }
}

int main(){
    struct node *root_node = NULL;
    root_node = insert_node(root_node, 10);
    insert_node(root_node, 10);
    insert_node(root_node, 30);
    insert_node(root_node, 25);
    insert_node(root_node, 36);
    insert_node(root_node, 56);
    insert_node(root_node, 78);
    printf("Binary Tree\n");
    print(root_node);
    printf("\nInorder Traversal\n"); // Inorder traversal gives nodes in non-decreasing order.
    printInOrder(root_node); 
    printf("\nPreorder Traversal\n");
    printPreOrder(root_node);
    printf("\nposorder Traversal\n");
    printPostOrder(root_node);
    return 0;
}