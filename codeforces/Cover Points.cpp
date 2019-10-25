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

    vector<ii> vii;
    int n, line=INT_MIN;
    cin >> n;

    lp(n){
        int x,y;
        cin>>x>>y;
        if(x+y > line) line = x+y;
    }

    cout << line << endl;


    return 0;
}

