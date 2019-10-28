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
    
    int n, l, r, cnt=0;
    ll lsum = 0 , hsum=0, i, val;
    cin >> n >> l >> r;
    
    for(i =1; i < (int) pow(2,l); i*=2 ){
        cnt++;
        lsum+=i;
    }
    
    for(i =cnt; i < n; i++)
        lsum++;
        
    cout << lsum << " ";
        
    cnt=0;
    for(i =1; i < (int) pow(2,r); i*=2 ){
        cnt++;
        hsum+=i;
    }
    
    val = i/2;
    for(i = cnt; i < n; i++)
        hsum+=val;
    
    cout << hsum << endl;
    
    return 0;
}
