// #include <bits/stdc++.h> 
// using namespace std; 
// #define endline '\n' 
// #define sep " " 
// #define FOR(i,begin,end) for (ll i=begin;i<=end;i++) 
// #define Fast_IO ios_base::sync_with_stdio(false);cin.tie(0) , cout.tie(0); 
// #define MODP ll(1000000009) 
// #define cinarr(arr,n) for(int i=0; i< n; i++) cin >> arr[i]; 
// #define coutarr(arr, x, n) for(int i=x; i< n; i++) {cout << arr[i]<<' ';} 
// #define pb push_back 
// #define F first 
// #define S second 
// #define yes cout << "Yes"<<endline; 
// #define mp make_pair 
// #define cin_pair_int(arr,n) for(int i=0; i<=n; i++) cin >> arr[i].first >> arr[i].second; 
// #define ll long long int 
// #define rep(i,t) for (ll i=0;i<t;i++) 
// #define revall(x) x.rbegin(),x.rend() 
// #define all(v) v.begin(),v.end() 
// typedef pair <int,int> pii; 
// inline string intToString(ll a){ char x[100]; sprintf(x, "%lld", a); string s = x; return s; } 
 
// ll ans=0; 
 
// void heapify(ll arr[], ll n, ll i) 
// { 
//     ll smallest = i; 
//     ll l = 2 * i + 1; 
//     ll r = 2 * i + 2; 
//     if (l < n and arr[l] < arr[smallest]) smallest = l; 
  
//     if (r < n && arr[r] < arr[smallest]) smallest = r; 
  
//     if (smallest != i)  
//     { 
//         swap(arr[i], arr[smallest]); 
//         ans++; 
//          heapify(arr, n, smallest); 
//     } 
// } 
  
// void heapSort(ll arr[], ll n) 
// { 
//     for (ll i = n / 2 - 1; i >= 0; i--) 
//         heapify(arr, n, i); 
  
//     for (ll i = n - 1; i >= 0; i--)  
//     { 
//         swap(arr[0], arr[i]); 
//         ans++; 
//         heapify(arr, i, 0); 
//     } 
// } 
 
// int main() 
// { 
//     ll n; 
//     cin >> n; 
//     ll arr[n]; 
//     for (ll i = 0; i < n; i++) 
//     { 
//         cin >> arr[i]; 
//     } 
     
//     ll t=sizeof(arr) / sizeof(arr[0]); 
//     heapSort(arr, t); 
//     cout << ans-1; 
// }

#include <iostream>  
using namespace std;  

void heapify(int a[], int n, int i)  
{  
    int largest = i;   
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    if (l < n && a[l] > a[largest])  
        largest = l;  
 
    if (r < n && a[r] > a[largest])  
        largest = r;  
 
    if (largest != i) {  

        swap(a[i],a[largest]);  
          
        heapify(a, n, largest);  
    }  
}  
 
void heapSort(int a[], int n)  
{  
  
    for (int i = n / 2 - 1; i >= 0; i--)  
        heapify(a, n, i);  

    // for (int i = n - 1; i >= 0; i--) {  

    //     swap(a[i],a[0]); 
          
    //     heapify(a, i, 0);  
    // }  
}  
/* function to print the array elements */  
void printArr(int a[], int n)  
{  
    for (int i = 0; i < n; ++i)  
    {  
        cout<<a[i]<<" ";  
    }  
          
}  
int main()  
{  
    int a[] = {60 , 10 , 20 , 80 , 100 , 120 , 90 
    , 70 , 40 , 140 , 88 , 92 , 66 , 148 , 160};  
    int n = sizeof(a) / sizeof(a[0]);  
    heapSort(a, n);  
    cout<<"\nAfter sorting array elements are - \n";    
    printArr(a, n);  
    return 0;  
}  