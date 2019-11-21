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
    
    int n,m,cnt=0;
    cin >> n >> m;
    bool ar[n][2*m];
    for(int i =0; i <n; i++){
        for(int j = 0; j <2*m; j++){
            cin >> ar[i][j];
        }
    }
    
    for(int i=0; i < n; i++){
        for(int j =0; j < 2*m; j+=2){
            if(ar[i][j] || ar[i][j+1]) cnt++;
        }
    }
    
    cout << cnt << endl;
    
    return 0;
}
