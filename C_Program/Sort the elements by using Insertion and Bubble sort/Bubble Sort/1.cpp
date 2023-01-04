// time complexity is O(n^2) and space complexity is O(1)

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void bubble(int a[] , int size){
    for(int i = 0 ; i < size - 1 ; i++){
        for(int j = 0 ; j < size - 1 - i ; j++){
            if(a[j] > a[j + 1]){
                swap(a[j] , a[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter no. of elemenets in the array : " << endl;
    cin >> n;
    int *a = new int(n);
    
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    bubble(a , n);

    for (int i = 0 ; i < n ; i++){
        cout << a[i] << " " ;
    }
    return 0;
}