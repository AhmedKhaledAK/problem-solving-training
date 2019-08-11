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
 
typedef long long ll;
const int N = 1e5;
int prices[N];
ll calPrice[N];
 
ll predicate(int n, int k){
    for(int i =0; i < n; i++){
        calPrice[i] = prices[i] + (i + 1) * (ll) k;
    }
    sort(calPrice, calPrice + n);
    ll ans = 0;
    for(int i =0; i < k; i++){
        ans+=calPrice[i];
    }
    return ans;
}
 
void solve(int n, int S){
    int l = 0, h = n+1;
    while(l<h-1){
        int mid = (l+h)/2;
        if(predicate(n,mid) <= S){
            l=mid;
        } else {
            h = mid;
        }
    }
    cout << l << " " << predicate(n,l);
}
 
int main() {
 
    int n, S;
    cin >> n >> S;
 
    for(int i =0; i < n; i++)
        cin >> prices[i];
 
    solve(n,S);
 
    return 0;
}
