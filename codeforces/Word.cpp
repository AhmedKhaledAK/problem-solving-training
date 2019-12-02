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
    
    string s;
    cin >> s;
    
    int cntl=0, cntu=0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] <= 90 && s[i] >= 65) cntu++;
        else if(s[i] <= 122 && s[i] >= 97) cntl++;
    }
    
    if(cntl >= cntu) transform(s.begin(), s.end(), s.begin(), ::tolower); 
    else transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << s << endl;
    return 0;
}
