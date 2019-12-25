#include <iostream>
#include<bits/stdc++.h>
#include <iomanip>
 
#define array_size(a) (sizeof(a)/sizeof(a[0]))
#define lpi(n) for(int i=0; i<n; i++)
#define lpiv(v,n) for(int i=v; i<n; i++)
#define lpj(n) for(int j=0; j<n; j++)
#define iii pair<int,pair<int,int>>
#define ii pair<int,int>
 
using namespace std;

typedef long long ll;

int main(int argc, const char * argv[]) {
    
    int n, modd=INT_MAX;
    
    ll sum=0;
    
    cin >> n;
    int ar[n];
    
    lpi(n) {
        cin >> ar[i];
        sum+=ar[i];
        if(ar[i]%2 !=0 && ar[i]<modd){
            modd=ar[i];
        }
    }
    
    if(sum%2==0){
        cout << sum << endl;
    } else {
        cout << sum-modd << endl;
    }
    
    return 0;
}
