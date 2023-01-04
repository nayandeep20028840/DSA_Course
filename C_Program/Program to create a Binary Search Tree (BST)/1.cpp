#include <iostream>
using namespace std;

int arr[6] = {34 , 54 , 66 , 10 , 90 , 11};

struct node {
   int value;
   node *left;
   node *right;
};

node* create(int val){
    node* temp = new node;
    temp -> value = val;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

node* insert_node(node* root , int val){
    if(root == NULL){
        return create(val);
    }
    if(val < root -> value){
        root -> left = insert_node(root -> left , val);
    }
    else if(val > root -> value){
        root -> right = insert_node(root -> right , val);
    }
    return root ;
}

void printTree(node *root){
   
    if(root == NULL){
        return ;
    }
    cout << root -> value << " : ";
    if(root -> left){
        cout << root -> left -> value << " " ;
    }
    if(root -> right){
        cout << root -> right -> value << " " ;
    }
    cout << endl;
    printTree(root -> left) ;
    printTree(root -> right) ;
   
}

int main(){
   
    node* root;
   
    for(int i = 0 ; i < 6 ; i++){
        root = insert_node(root, arr[i]);
    }
   
    printTree(root);
}