#include <iostream>
#include<bits/stdc++.h>
 
#define array_size(a) (sizeof(a)/sizeof(a[0]))
#define lpi(n) for(int i=0; i<n; i++)
#define lpiv(v,n) for(int i=v; i<n; i++)
#define lpj(n) for(int j=0; j<n; j++)
#define iii pair<int,pair<int,int>>
#define ii pair<int,int>
 
using namespace std;
 
typedef long long ll;
 
int main(int argc, const char * argv[]) {
    
    int n,in;
    cin >> n;
    int ar[n];
    lpi(n){
        cin >> ar[i];
        if(ar[i] == n) in=i;
    }
    
    
    lpi(in){
        if(ar[i]>ar[i+1]){
            cout << "NO"<< endl;
            return 0;
        }
    }
    
    
    
    for(int i = n-1; i > in; i--){
        if(ar[i]>ar[i-1]){
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    
    return 0;
}
