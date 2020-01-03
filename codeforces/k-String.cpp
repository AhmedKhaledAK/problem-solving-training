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
#define pf push_front
#define mp make_pair
#define vi vector<int>
#define vip vector<pair<int,int>>
#define pqig priority_queue<int>
#define pqil priority_queue<int, vector<int>, greater<int>>
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

string solve(int k, string s){
    int freq[26];
    memset(freq, 0, sizeof(freq));
    lpi(s.length())
        freq[s[i]-97]++;

    string ans;
    lpi(26){
        if(freq[i]!=0 && freq[i]%k!=0) return "-1";
        if(freq[i]==0)continue;
        lpj(freq[i]/k){
            ans+=(i+97);
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    
    fastio;

    int k;
    cin >> k;
    string s;
    cin >> s;

    string ans = solve(k,s);
    if(ans=="-1") cout << "-1";
    else lpi(k)cout << ans;
    cout << endl;

    return 0; 
}
