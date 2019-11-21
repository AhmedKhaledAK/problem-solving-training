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
    
    int t;
    double a,sides;
    cin >> t;
    
    while(t--){
        cin >> a;
        sides = (360/(180-a));
        if(sides == (int)sides){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
