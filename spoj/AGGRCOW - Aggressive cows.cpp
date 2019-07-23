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

bool predicate(int x[], int n, int c, int mid){
    int cpos = x[0], cows = 1; // one cow is already put at the 1st position
    for(int i = 1; i < n; i++){
        if(x[i] - cpos >= mid){
            cpos = x[i];
            cows++;
            if(cows==c)
                return true;
        }
    }
    return false;
}

int bs(int x[], int n, int c){
    // the search space limits are the limits of x
    int s = 0, e = x[n-1], ans = 0;
    while(e-s>=1){
        int mid = (e+s)/2;
        // question: if all cows can be put in stalls with a distance "mid" (i.e true), then all values < mid are true also
        if(predicate(x,n,c,mid)){
            if(mid > ans)
                ans = mid;
            s=mid+1;
        }else
            e=mid;
    }
    return ans;
}


int main() {


    int t;
    cin >> t;

    while(t--){
        int n, c;
        cin >> n >> c;
        int x[n];

        for(int i = 0; i < n; i++)
            cin >> x[i];

        sort(x,x+n);
        cout << bs(x,n,c) << "\n";
    }

    return 0;
}
