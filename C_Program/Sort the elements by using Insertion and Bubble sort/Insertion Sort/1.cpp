// Time complexity -> worst case -> O(N^2) ::: best case -> O(N)

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
void insertion(int arr[] , int n){
    int i, key, j;
    for (i = 1 ; i < n ; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int n;
    cout << "Enter no. of elemenets in the array : " << endl ;
    cin >> n ; 
    
    int *a = new int(n);
    
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    insertion(a , n);
    
    for (int i = 0 ; i < n ; i++){
        cout << a[i] << " " ;
    }
    cout << endl;
    return 0;
}