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
#define filein(ff) freopen(ff, "r", stdin);
#define fileout(ff) freopen(ff, "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
 
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
long long dist(pair<ll, ll> u, pair<ll, ll> v) {
  return 
      abs(u.fi - v.fi)  + abs(u.se - v.se);
}





int main(int argc, const char * argv[]) {
    
    fastio;

    int n,in,idx=0;
    cin >> n;

    int arg[n+1], art[n+1];
    deque<int> nottook;

    memset(art, 0, sizeof(art));

    lpiv(1, n+1){
        cin >> in;
        arg[i] = in;
        if(in!=0) art[in]=i;
    }

    lpiv(1, n+1){
        if(art[i]==0){
            nottook.pb(i);
            //idx=i;
        }
    }

    lpiv(1, n+1){
        if(arg[i]==0){
            arg[i] = nottook.front();
            if(arg[i] == i){
                nottook.pop_front();
                nottook.pb(arg[i]);
                arg[i]=nottook.front();
            }
            if(arg[i]==i){
                swap(arg[i],arg[idx]);
            }
            nottook.pop_front();
            idx=i;
        }
    }

    lpiv(1,n+1) cout << arg[i] << " ";
    
    return 0; 
}
