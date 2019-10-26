#include <iostream>
#include<bits/stdc++.h>

#define array_size(a) (sizeof(a)/sizeof(a[0]))
#define lp(n) for(int i=0; i<n; i++)
#define lp1(n) for(int i=1; i<n; i++)
#define loop(n) for(int j=0; j<n; j++)
#define iii pair<int,pair<int,int>>
#define ii pair<int,int>

using namespace std;

typedef long long ll;

int main(int argc, const char * argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int n,s,e;
    cin>>n;

    string str;
    cin>>str;

    for(int i = 0; i < str.length(); i++){
        if(n%(i+1)!=0) continue;
        s = 0;
        e = i;
        while(e > s){
            char temp = str[e];
            str[e] = str[s];
            str[s] = temp;
            e--;
            s++;
        }
    }

    cout << str;

    return 0;
}

