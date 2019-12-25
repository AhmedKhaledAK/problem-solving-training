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


bool isright(bool ar[], int n, int i){
    if(i >= n || i < 0) return true;
    return ar[i];
}

int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(0);
    
    int n,a,cnt=0;
    cin >> n >> a;
    
    bool cities[n];
    bool c1=false,c2=false;
    a-=1;
    
    lpi(n) cin >> cities[i];
    
    if(cities[a]) cnt++;
    
    for(int i=1; i < n; i++){
        
        if(a-i < 0 && a+i >= n) break;
        
        if(a-i >= 0 && cities[a-i]) c1=true;
        if(a+i < n && cities[a+i]) c2 = true;
        
        if(c1&&c2) cnt+=2;
        else if((c1&& a+i>=n) || (c2&& a-i<0)) cnt++;
        
        c1=c2=false;
    }
    
    cout << cnt << endl;
    
    return 0;
}
