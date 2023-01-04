#include <iostream>
using namespace std;

struct node{
    int val;
    node* left = nullptr;
    node *right = nullptr;
    node() {}
    node(int val): val(val) {}
};

node* insert_node(node* root, int value){
    if (root == nullptr){
        return new node(value);
    }
    if (value < root->val){
        root->left = insert_node(root->left, value);
    }
    else{
        root->right = insert_node(root->right, value);
    }
    return root;
}
node* findMinimum(node* root){
    while (root->left) {
        root = root->left;
    }
    return root;
}
node* findMaximum(node* root){
    while(root->right){
        root = root->right;
    }
    return root;
}

node* findSuccessor(node* root, int key){
    if(root == nullptr){
        return nullptr;
    }
    node* succ = nullptr;
    while(1){
        if(key < root -> val){
            succ = root ;
            root = root -> left;
        }
        else if(key > root -> val){
            root = root -> right ;
        }
        else {
            if(root -> right){
                succ = findMinimum(root -> right);
            }
            break;
        }
        if(!root){
            return succ;
        }
    }
    return succ;
}

node* findpredecessor(node* root, int key){
    if(root == nullptr){
        return nullptr;
    }
    node* succ = nullptr;
    while(1){
        if(key < root -> val){
            root = root -> left;
        }
        else if(key > root -> val){
            succ = root ;
            root = root -> right ;
        }
        else {
            if(root -> left){
                succ = findMaximum(root -> left);
            }
            break;
        }
        if (!root){
            return succ;
        }
    }
    return succ;
}

int main()
{
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
    node* root = nullptr;
    for(int key: keys){
        root = insert_node(root, key);
    }
    for(int key: keys){
        node* succ = findSuccessor(root, key);
        if (succ != nullptr) {
            cout << "The successor of node " << key << " is " << succ->val;
        }
        else{
            cout << "No Successor exists for node " << key;
        }
        cout << endl;
    }
    for(int key: keys){
        node* succ = findpredecessor(root, key);
        if(succ != nullptr){
            cout << "The predecessor of node " << key << " is " << succ->val;
        }
        else{
            cout << "No predecessor exists for node " << key;
        }
        cout << endl;
    }
    return 0;
}