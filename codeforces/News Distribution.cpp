#include <iostream>
#include<bits/stdc++.h>
 
#define array_size(a) (sizeof(a)/sizeof(a[0]))
#define lpi(n) for(int i=0; i<n; i++)
#define lpiv(v,n) for(int i=v; i<n; i++)
#define lpj(n) for(int j=0; j<n; j++)
#define iii pair<int,pair<int,int>>
#define ii pair<int,int>
 
using namespace std;
 
const int N = 5*100000+1;
 
int r[N], p[N];
 
typedef long long ll;
 
void makeset(int n) { 
    lpi(n){
        p[i] = i;
        r[i]=1;
    } 
} 
 
int parent(int x){
    if (p[x] != x) { 
        p[x] = parent(p[x]); 
    }
    return p[x];
}
 
void uni(int x, int y){
    x = parent(x);
    y=parent(y);
    if(x==y)return;
    if(r[x] < r[y]) swap(x,y);
    p[y] = x;
    r[x] += r[y];
}
 
int main(int argc, const char * argv[]) {
    
    int n,m,k,e;
    bool isfirst;
    cin >> n>>m;
    
    makeset(n);
    
    lpi(m){
        cin>>k;
        isfirst=true;
        lpj(k){
            int ee;
            cin >> ee;
            ee--;
            if(!isfirst) uni(ee,e);
            isfirst=false;
            e=ee;
        }
    }
    
    lpi(n){
        cout << r[parent(i)] << " ";
    }
    cout << endl;
    
    return 0;
}
