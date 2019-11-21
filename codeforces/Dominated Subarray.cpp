#include <iostream>
#include<bits/stdc++.h>
 
#define array_size(a) (sizeof(a)/sizeof(a[0]))
#define lpi(n) for(int i=0; i<n; i++)
#define lpiv(v,n) for(int i=v; i<n; i++)
#define lpj(n) for(int j=0; j<n; j++)
#define iii pair<int,pair<int,int>>
#define ii pair<int,int>
 
using namespace std;
 
typedef long long ll;
 
int ar[2*100000];
 
int main(int argc, const char * argv[]) {
 
    int t,n;
    cin >> t;
    
    while(t--){
        cin >> n;
        vector<int> pos(n+1,-1);
        lpi(n) cin >> ar[i];
        int ans = INT_MAX;
        lpi(n){
            if(pos[ar[i]] != -1){
                ans = min(ans, i-pos[ar[i]]+1);
            }
            pos[ar[i]] = i;
        }
        if(ans > n)
            ans = -1;
        cout << ans << endl;
    }
    
    return 0;
}
