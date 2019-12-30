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
    
    int t,n;
    bool flag=false;
    
    cin >> t;
    
    while(t--){
        cin >> n;
        int ar[n];
        lpi(n)cin >> ar[i];
        for(int i =0; i < n-1; i++){
            if(abs(ar[i]-ar[i+1]) >= 2){
                cout << "YES" << endl;
                cout << i+1 << " " << i+2 << endl;
                flag=true;
                break;
            }
        }
        if(!flag) cout << "NO" << endl;
        flag=false;
    }
    
    return 0;
}
