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
 
bool ar[5001];
 
int main(int argc, const char * argv[]) {
    
    int n,a,cnt=0;
    cin >> n;
    
    lpi(n){
        cin >> a;
        if(!ar[a] && a<=n) {
            cnt++;
            ar[a]=true;
        }
    }
    
    cout << n-cnt << endl;
    
    return 0;
}
