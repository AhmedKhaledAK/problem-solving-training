#include <iostream>
#include<bits/stdc++.h>
#include <iomanip>
 
#define array_size(a) (sizeof(a)/sizeof(a[0]))
#define lpi(n) for(int i=0; i<n; i++)
#define lpiv(v,n) for(int i=v; i<n; i++)
#define lpj(n) for(int j=0; j<n; j++)
#define iii pair<int,pair<int,int>>
#define ii pair<int,int>
 
using namespace std;
 
typedef long long ll;
 
int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(0);
    
    int t,n, k1,k2, mx=-1;
    bool flag=false;
    
    cin >> t;
    
    while(t--){
        cin >> n >> k1 >> k2;
        int ark1[k1];
        int ark2[k2];
        
        lpi(k1){
            cin >> ark1[i];
            mx = max(mx, ark1[i]);
        }
        flag=true;
        lpi(k2) {
            cin >> ark2[i];
            if(ark2[i]>mx){
                mx=ark2[i];
                flag=false;
            }
        }
        
        if(!flag) cout << "NO" << endl;
        else cout << "YES" << endl;
        mx=-1;
        
    }
    
    return 0;
}
