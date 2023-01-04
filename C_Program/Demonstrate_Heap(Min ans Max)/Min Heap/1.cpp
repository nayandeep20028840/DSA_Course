#include <bits/stdc++.h>
using namespace std;

void TopDownHeapify(int a[] , int n ){
    for(int i = 0 ; i < n ; ++i){
        int key = a[i];
        int c = i ;
        int p = (c - 1) / 2 ;
        while(c > 0 && key > a[p]){
            a[c] = a[p] ;
            c = p ;
            p = (c - 1) / 2 ;
            a[c] = key ;
        }
    }
}

void heapsort(int a[] , int n){
    TopDownHeapify(a , n);
    for(int i = n - 1 ; i >= 0 ; --i){
        int temp = a[i];
        a[i] = a[0] ;
        a[0] = temp ;
        TopDownHeapify(a , i);
    }
    return ;
}

void print(int a[] , int n ){
    for(int i = 0 ; i < n ; ++i){
        cout << a[i] << " ";
    }
    cout << endl;
    return ;
}

int main(){
    int a[] = {60 , 10 , 20 , 80 , 100 , 120 , 90 
    , 70 , 40 , 140 , 88 , 92 , 66 , 148 , 160};
    int n = sizeof(a) / sizeof(a[0])  ;
    // cout << n << endl; working 
    cout << "Array before Heap sort : " << endl;
    print(a , n);
    heapsort(a , n);
    cout << "After heap sorting array elements are : " << endl;   
    print(a, n);  
}