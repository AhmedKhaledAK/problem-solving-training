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

    int t,shift;
    ll tsum, no, n;
    cin >> t;
    
    while(t--){
        cin >> n;
        tsum = (n*(n+1))/2;
        shift = 0;
        no = 1;
        while((no << shift) <= n){
            tsum-=(no << shift)*2;
            shift++;
        }
        cout << tsum << endl;
    }
    
    return 0;
}

