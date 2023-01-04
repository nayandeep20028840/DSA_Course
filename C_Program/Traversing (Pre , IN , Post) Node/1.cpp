#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

Node* newNode(int data){
    Node* temp = new Node;
    temp-> data = data;
    temp-> left = temp->right = NULL;
    return temp;
}

void printPreOrder(struct Node* node){
    if(node == NULL) return;
    cout << node -> data <<" ";
    printPreOrder(node -> left);
    printPreOrder(node -> right);
}

void printInOrder(struct Node* node){
    if(node == NULL) return;
    printInOrder(node -> left);
    cout << node->data << " ";
    printInOrder(node -> right);
}

void printPostOrder(struct Node* node){
    if(node == NULL) return;
    printPostOrder(node -> left);
    printPostOrder(node -> right);
    cout << node -> data << " ";
}

int main()
{
    struct Node* root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    
    printInOrder(root); 
    cout << endl;
    printPreOrder(root);
    cout << endl;
    printPostOrder(root);
} 