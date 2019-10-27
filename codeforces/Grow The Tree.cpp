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

    int n;
    ll x=0,y=0;
    cin >> n;

    int ar[n];

    lpi(n)
        cin>>ar[i];

    sort(ar,ar+n);
    int i = 0, j = n-1;
    while(i<=j){
        if(i==j) x+=ar[i];
        else{
            y+=ar[i];
            x+=ar[j];
        }
        i++;
        j--;
    }

    cout << x*x+y*y;

    return 0;
}

