#include <iostream>
#include<bits/stdc++.h>
#include <iomanip>
 
#define array_size(a) (sizeof(a)/sizeof(a[0]))
#define lpi(n) for(int i=0; i<n; i++)
#define lpiv(v,n) for(int i=v; i<n; i++)
#define lpj(n) for(int j=0; j<n; j++)
#define iii pair<int,pair<int,int>>
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define filein(ff) freopen(ff, "r", stdin)
#define fileout(ff) freopen(ff, "w", stdout)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0)
 
using namespace std;

typedef long long ll;


ll fastpow(ll nodess, ll num) {
    if (!num)
        return 1;
    if (num % 2)
        return nodess * fastpow(nodess, num - 1)/*%mod*/;
    ll p = fastpow(nodess, num / 2);
    // p %= mod;
    p *= p;
    // p %= mod;
    return p;
}
 
ll my_mod(ll num, ll mod) {
    ll reto = num % mod;
    while (reto < 0)
        reto += mod;
    return reto;
}
 
ll gcd(ll u, ll v) { return !u ? v : gcd(v % u, u); }

ll dist(pair<ll, ll> u, pair<ll, ll> v) {
    return abs(u.fi - v.fi)  + abs(u.se - v.se);
}


int main(int argc, const char * argv[]) {
    
    fastio;

    int n, mnl=INT_MAX, mxr=-1, il=-1, ir=-1, mx=-1,mn=INT_MAX;
    cin >> n;

    bool flag=0;
    lpi(n){
        int in1,in2;
        cin >> in1 >> in2;
        if(in1<=mnl && in2>=mxr){
            mnl=in1;
            mxr=in2;
            flag=1;
            ir=i;
        }
        if(in1<=mn)mn=in1;
        if(in2>=mx)mx=in2;
    }

    if(flag && mn==mnl && mx==mxr) cout << ir+1 << endl;
    else cout << -1 << endl;


    return 0; 
}
