#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <array>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <iterator>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

int solve(int a[], int b[], int n){
    if(n==1) return a[0] + b[0];
    int maxa = INT_MIN, maxb = INT_MIN;
    for(int l = 0; l < n; l++){
        int aor = a[l];
        int bor = b[l];
        for(int r=l+1; r < n; r++){
            aor |= a[r];
            if(aor > maxa)
                maxa = aor;

            bor |= b[r];
            if(bor > maxb)
                maxb = bor;
        }
    }
    return maxa+maxb;
}

int main() {

    int n;
    cin>>n;
    int a[n], b[n];

    for(int i =0; i < n; i++)
        cin >> a[i];
    for(int i =0; i < n; i++)
        cin >> b[i];

    cout << solve(a,b,n);

    return 0;
}
