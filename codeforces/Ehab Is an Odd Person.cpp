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
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    
    int n, even=0;
    cin >>n;
    int ar[n];
    
    lpi(n) {
        cin>>ar[i];
        if(ar[i] % 2 == 0) even++;
    }
    
    if(even < n && even !=0) sort(ar,ar+n);
    
    lpi(n)cout << ar[i] << " ";
    
    return 0;
}
