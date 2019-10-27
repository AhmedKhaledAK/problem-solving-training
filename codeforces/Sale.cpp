#include <iostream>
#include<bits/stdc++.h>

#define array_size(a) (sizeof(a)/sizeof(a[0]))
#define lpi(n) for(int i=0; i<n; i++)
#define lpi1(n) for(int i=1; i<n; i++)
#define lpj(n) for(int j=0; j<n; j++)
#define iii pair<int,pair<int,int>>
#define ii pair<int,int>

using namespace std;

typedef long long ll;

int main(int argc, const char * argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int n,m, mx=0;
    cin >> n >> m;
    bool neg=false;
    int ar[n];

    lpi(n) {
        cin >> ar[i];
        if(ar[i] < 0) neg = true;
    }
    if(!neg) {
        cout << 0;
        return 0;
    }
    sort(ar,ar+n);

    lpi(m){
        if(ar[i] > 0) break;
        mx+=abs(ar[i]);
    }

    cout << mx;

    return 0;
}

