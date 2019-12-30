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


int solve(ll ar[], int n){
    int cnt=0;
    ll gcf;
    if(n==1){
        gcf=ar[0];
    }
    else {
        gcf = gcd(ar[0], ar[1]);
        lpiv(2,n){
            gcf = gcd(gcf, ar[i]);
            if(gcf==1) return 1;
        }
    }
    for(int i =1; i <= sqrt(gcf); i++){
        if(gcf%i==0){
            if(gcf/i!=i){
                cnt+=2;
            } else cnt++; 
        }       
    }
    return cnt;
}



int main(int argc, const char * argv[]) {
    
    fastio;

    int n;
    cin >> n;
    ll ar[n];

    lpi(n)
        cin >> ar[i];

    cout << solve(ar,n) << endl;
    
    
    return 0; 
}
