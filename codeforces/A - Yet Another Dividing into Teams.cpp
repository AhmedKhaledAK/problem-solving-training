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

int ar[100];

/* maximum 2 teams, minimum 1 team */

int main(int argc, const char * argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int q,n;
    bool fl = false;
    cin>>q;
    while(q--){
        fl=false;
        cin>>n;
        lp(n) cin>>ar[i];
        sort(ar,ar+n);
        lp1(n){
            if(ar[i] - ar[i-1] == 1){
                fl = true;
                break;
            }
        }
        cout << (fl ? 2 : 1) << "\n";
    }

    return 0;
}

