#include <iostream>
using namespace std;

int arr[6] = {34 , 54 , 66 , 10 , 90 , 11};
int ar[6] = {1 , 2 , 3 , 4 , 5 , 6};

struct node {
   int value;
   node *left;
   node *right;
};

typedef struct node* NODE;

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

int HOBST(NODE root){
    if(root == nullptr) return -1;
    return 1 + max(HOBST(root -> left) , HOBST(root -> right));
}

int main(){
    NODE root = nullptr;
    for(int i = 0 ; i < 6 ; i++){
        root = insert_node(root, ar[i]);
    }
    cout << HOBST(root) << endl;
}