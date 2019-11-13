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
 
int main(int argc, const char * argv[]) {
 
    int t,x,y;
    cin >> t;
    
    while(t--){
        cin >> x >> y;
        if(x == y) {
            cout << "YES" << endl;
            continue;
        }
        else if(x == 1){ 
            cout << "NO" << endl;
            continue;
        }
        else if(x == 2 && (y != 3 && y != 1)) {
            cout << "NO" << endl;
            continue;
        }
        else if(x == 3 && (y != 2 && y != 1)) {
            cout << "NO" << endl;
            continue;
        }
        
        cout << "YES" << endl;
  
    }
    
    return 0;
}
