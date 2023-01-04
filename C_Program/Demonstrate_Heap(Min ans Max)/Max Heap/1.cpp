#include <bits/stdc++.h>
using namespace std;

void bottomUpHeapify(int a[] , int n ){
    for(int i = n / 2 - 1 ; i >= 0 ; --i){
        int item = a[i];
        int c = ((2 * i) + 1) ; 
        while(c + 1 <= n - 1){
            if(c + 1 <= n - 1 && a[c] < a[c + 1]){
                c++;
            }
            if(item < a[c]){
                a[i] = a[c];
                i = c ;
            }
            break;
        }
        a[i] = item;
    }
}

void heapsort(int a[] , int n){
    bottomUpHeapify(a , n);
    for(int i = n - 1 ; i >= 0 ; --i){
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp ;
        bottomUpHeapify(a , i);
    }
    return ;
}

void print(int a[] , int n ){
    for(int i = n - 1 ; i >= 0 ; --i){
        cout << a[i] << " ";
    }
    cout << endl;
    return ;
}

int main(){
    int a[] = {80 , 160 , 70 , 10 , 20 , 40 , 110 
    , 10 , 20 , 80 , 30 , 60 , 88 , 90 , 100};
    int n = sizeof(a) / sizeof(a[0])  ;
    // cout << n << endl; working 
    cout << "Array before Heap sort : " << endl;
    print(a , n);
    heapsort(a , n);
    cout << "After heap sorting array elements are : " << endl;   
    print(a, n);  
}