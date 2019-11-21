#include <iostream>
#include<bits/stdc++.h>
 
#define array_size(a) (sizeof(a)/sizeof(a[0]))
#define lpi(n) for(int i=0; i<n; i++)
#define lpiv(v,n) for(int i=v; i<n; i++)
#define lpj(n) for(int j=0; j<n; j++)
#define iii pair<int,pair<int,int>>
#define ii pair<int,int>
 
using namespace std;
 
int main(int argc, const char * argv[]) {
    
    string s;
    cin >> s;
    
    bool isv = false, ish = false;
    
    lpi(s.length()){
        if(s[i] == '0'){
            if(isv){
                cout << "1 1" << endl;
                isv=false;
            } else {
                cout << "3 1" << endl;
                isv=true;
            }
        } else {
            if(ish){
                cout << "1 1" << endl;
                ish=false;
            } else {
                cout << "1 3" << endl;
                ish=true;
            }
        }
    }
    
    return 0;
}
