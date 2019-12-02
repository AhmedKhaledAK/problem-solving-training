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
    
    int n;
    cin >> n;
    double sum =0,in;
    lpi(n){
        cin >> in;
        sum+=in;
    }
    cout << fixed;
    cout << setprecision(5);
    cout << sum/n << endl;
    return 0;
}
