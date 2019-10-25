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

    /* this problem can be more general by processing the integer digit by digit and check if it is lucky, but for the porpose of this problem, we may brute force it because its
    input is so small */

    int n;
    cin >> n;



    if(n%4==0 || n%7==0 || n%44==0 || n%47==0 || n%74==0 || n%77==0 || n%444==0 || n%447==0
        || n%474==0 || n%477==0 || n%744==0 || n%747==0 || n%774==0 || n%777==0) cout << "YES";
    else cout << "NO";

    return 0;
}

