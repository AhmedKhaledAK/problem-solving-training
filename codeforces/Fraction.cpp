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

    int n;
    cin>>n;

    int maxa = 1, maxb = n-1;
    bool cop = true;

    for(int a = 1; a <= n/2; a++){
        int b = n-a;
        cop = true;
        for(int d = 2; d <=a; d++){
            if(a%d==0 && b%d == 0){
                cop = false;
                break;
            }
        }
        if(cop && (double) a / (double) b > (double) maxa / (double) maxb) {
            maxa = a;
            maxb = b;
        }
    }

    cout << maxa << " " << maxb;

    return 0;
}

