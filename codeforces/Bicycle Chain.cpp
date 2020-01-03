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


int solve(int n, int m, int pedals[], int rear[]){
    int mx=-1,cnt=1;
    lpi(m){
        lpj(n){
            if(rear[i]%pedals[j]==0){
                if(rear[i]/pedals[j]>mx){
                    mx=rear[i]/pedals[j];
                    cnt=1;
                } else if(rear[i]/pedals[j]==mx){
                    cnt++;
                }
            }
        }
    }
    return cnt;
}


int main(int argc, const char * argv[]) {
    
    fastio;

    int n,m,mx=-1,cnt=1,mod;
    cin >> n;
    int pedals[n];
    lpi(n)cin >> pedals[i];
    cin >> m;
    int rear[m];
    lpi(m) cin >> rear[i];

    cout << solve(n,m,pedals,rear) << endl;

    return 0; 
}
