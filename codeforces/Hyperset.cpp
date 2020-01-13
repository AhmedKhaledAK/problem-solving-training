#include <iostream>
#include<bits/stdc++.h>
#include <iomanip>
 
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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); 
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
    
    int n,k,same=0,diff=0,cnt=0;
    cin >> n>>k;
    string cards[n];
    string ans;
    unordered_map<string, bool> mp;
    lpi(n){
        cin>>cards[i];
        mp[cards[i]]=1;
    }
    
    lpi(n){
        lpjv(i+1,n){
            same=diff=0;
            ans="";
            for(int x=0; x<k; x++){
                if(cards[i][x]==cards[j][x]){
                    ans+=cards[i][x];
                    same++;
                } else if(cards[i][x]!=cards[j][x]){
                    if(cards[i][x]=='S' && cards[j][x]=='T'){
                        ans+='E';
                    } else if(cards[i][x]=='S' && cards[j][x]=='E'){
                        ans+='T';
                    } else if(cards[i][x]=='T' && cards[j][x]=='S'){
                        ans+='E';
                    } else if(cards[i][x]=='E' && cards[j][x]=='S'){
                        ans+='T';
                    } else if(cards[i][x]=='T' && cards[j][x]=='E'){
                        ans+='S';
                    } else if(cards[i][x]=='E' && cards[j][x]=='T'){
                        ans+='S';
                    } 
                    diff++;
                }
            }
 
            if(mp[ans])cnt++;
        }
    }
    cout << cnt/3 << endl;
    return 0; 
}
