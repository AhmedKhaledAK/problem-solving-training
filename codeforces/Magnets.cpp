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
 
 
int magnets(int n){
    int i, m, v, cnt=1;
    scanf("%d",&m);
    for(int i = 1; i < n; i++){
        scanf("%d",&v);
        if(v != m) {
            cnt++; m=v;
        }
    }
    printf("%d",cnt);
}
 
int main(int argc, const char * argv[]) {
    
    int n;
    scanf("%d",&n);
    magnets(n);
    
    return 0;
}
