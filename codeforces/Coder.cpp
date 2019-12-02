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
    
    int n,cnt=0;
    cin >> n;
    char mat[n][n];
    
    for(int i =0; i < n; i++){
        if(i%2 ==0){
            for(int j =0; j < n; j++){
                if(j%2==0){
                    mat[i][j] = 'C';
                    cnt++;
                }else mat[i][j] = '.';
            }
        } else {
            for(int j =0; j < n; j++){
                if(j%2==0)
                    mat[i][j] = '.';
                else {
                    mat[i][j] = 'C';
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    lpi(n){
        lpj(n){
            cout << mat[i][j];
        }
        cout << endl;
    }
    
    
    return 0;
}
