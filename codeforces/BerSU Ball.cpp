#include<bits/stdc++.h>
 
#define arrsz(a) (sizeof(a)/sizeof(a[0]))
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

int idx[2*3*100000+1];

int main(int argc, const char * argv[]) {
 
    
    int n, m, mn, cnt=0;
    cin >> n;
    int boys[n];
    lpi(n) cin >> boys[i];
    cin >> m;
    int girls[m];
    lpi(m) cin >> girls[i];

    sort(boys, boys+n);
    sort(girls, girls+m);

    lpi(n){
        lpj(m){
            if ((abs(boys[i] - girls[j]) <= 1)) {
                cnt++;
                girls[j] = 1000;
                break;
            }
        }
    }

    cout << cnt << endl;

    return 0; 
}   
