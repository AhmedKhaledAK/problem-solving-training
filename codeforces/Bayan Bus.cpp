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
char mat[4][11];
 
int main(int argc, const char * argv[]) {
    
    int k;
    cin >> k;
    
    for(int j = 0; j < 11; j++){
        for(int i =0; i < 4; i++){
            if(k==0){
                mat[i][j] = '#';
                if(j!=0 && i==2) mat[i][j]='.';
            }
            else {
                if(j!= 0 && i ==2) mat[i][j] ='.';
                else {
                    
                    mat[i][j] = 'O';
                    k--;
                
                }
            }
        }
    }
    cout << "+------------------------+" << endl;
    lpj(4){
        cout << "|";
        lpi(11){
            cout << mat[j][i] << '.';
        }
        if(j==0){
            cout << "|D|)";
        } else if(j==3){
            cout << "|.|)";
        }
        else {
            if(j==2) cout << "..|";
            else cout << "|.|";
        }
        cout << endl;
    }
    cout << "+------------------------+";
 
    
    return 0;
}
