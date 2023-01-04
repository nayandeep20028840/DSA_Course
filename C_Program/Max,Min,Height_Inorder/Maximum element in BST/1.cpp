#include <iostream>
using namespace std;

int arr[6] = {34 , 54 , 66 , 10 , 90 , 11};
int ans = -1e9;

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
    if(root == nullptr) return -1e9;
    ans = max(root -> value , ans);
    HOBST(root -> right);
    return ans;
}

int main(){
    NODE root;
    for(int i = 0 ; i < 6 ; i++){
        root = insert_node(root, arr[i]);
    }
    cout << HOBST(root) << endl;
}