#include<bits/stdc++.h>
 
#define array_size(a) (sizeof(a)/sizeof(a[0]))
#define lpi(n) for(int i=0; i<n; i++)
#define lpiv(v,n) for(int i=v; i<n; i++)
#define lpj(n) for(int j=0; j<n; j++)
#define lpjv(v,n) for(int j=v; j<n; j++)
#define iii pair<int,pair<int,int>>
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
#define vi vector<int>
#define vip vector<pair<int,int>>
#define pqig priority_queue<int>
#define pqil priority_queue<int, vector<int>, greater<int>>
#define filein(ff) freopen(ff, "r", stdin)
#define fileout(ff) freopen(ff, "w", stdout)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define sz(v) (int)v.size()
 
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
 
ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}
 
int main(int argc, const char * argv[]) {
 
    fastio;
 
    int g [5][5];
    ll sum, mx=-1;
 
    lpi(5)
        lpj(5)
            cin >> g[i][j];
 
    vector<int> stds;
    lpiv(1,6) stds.pb(i);
 
    do {
        sum = 0;
        for (int i =0; i < sz(stds); i++){
            for (int j = i; j < sz(stds) && j+1 < sz(stds); j+=2) {
                sum += g[stds[j]-1][stds[j+1]-1] + g[stds[j+1]-1][stds[j]-1];
            }
        }
        mx = max(sum, mx);
    } while(next_permutation(stds.begin(), stds.end())); 
        
    
    cout << mx <<"\n";
 
    return 0; 
}
