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
 
 
int chars [26];
 
int main(int argc, const char * argv[]) {
 
    int t,n,x,a,b,cnt=0,s,e;
    cin >> t;
    
    while(t--){
        cin >> n >> x >> a>>b;
        s = min(a,b);
        e = max(a,b);
        cnt =0;
        while(cnt != x){
            if(e<n){
                e++;
            } else if(s>1){
                s--;
            }
            cnt++;
        }
        cout << abs(e-s) << endl;
    }
    
    return 0;
}
