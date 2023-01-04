#include <bits/stdc++.h>
using namespace std;

struct heap{
    int *arr;
    int capacity;
    int size;
    heap(int c){
        capacity = c;
        size = 0;
        arr = new int[c];
    }
    int right(int i) { return (2 * i) + 2; }
    int left(int i) { return (2 * i) + 1; }
    int parent(int i){
        return (i - 1) / 2;
    }
    void insert(int x){
        if(size==capacity) return;
        size++;
        arr[size-1] = x;
        for(int i = size-1;i!=0 && arr[i]>arr[parent(i)];){
            swap(arr[i],arr[parent(i)]);
            i = parent(i);
        }
    }
    void heapfiy(int x){
        
    }
};



int main()
{
    int n;
    heap h(n);

    

    return 0;
}