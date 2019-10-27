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

int n,m,j;
ll sum=0, hsum=0;

int main(int argc, const char * argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    cin >> n;
    int ar[n];
    lpi(n) {
        cin >> ar[i];
        sum+=ar[i];
    }

    hsum=sum;

    cin >> m;
    int q[m];
    lpi(m) cin >> q[i];

    sort(ar,ar+n, greater<int>());

    lpi(m){
        sum-=ar[q[i]-1];
        cout << sum << endl;
        sum=hsum;
    }

    return 0;
}

