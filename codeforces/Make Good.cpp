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
 
using namespace std;
 
typedef long long ll;
 
int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(0);
 
    int t, n, in;
    ll sum = 0, orx =0;
 
    cin >> t;
 
    while(t--){
        cin >> n;
        lpi(n){
            cin >> in;
            sum+=in;
            orx ^= in;
        }
 
        cout << 2 << endl;
        cout << orx << " " << (sum+orx) << endl;
        sum=orx=0;
    }
    
    return 0; 
}
