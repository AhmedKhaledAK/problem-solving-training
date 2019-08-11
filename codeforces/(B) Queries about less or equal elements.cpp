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
 
const int N = 2*1e5;
 
int a[N];
int b[N];
int ans[N];
 
int bs(int el, int n){
    int s = 0, e = n;
    while(s<e){
        int mid = s+(e-s)/2;
        if(a[mid] <= el)
            s=mid+1;
        else
            e=mid;
    }
    return s;
}
 
void solve(int n, int m){
    for(int i = 0; i < m; i++)
        ans[i] = bs(b[i], n);
 
    for(int i = 0; i < m; i++)
        cout << ans[i] << " ";
}
 
 
int main() {
 
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a,a+n);
 
    for(int i = 0; i < m; i++)
        cin >> b[i];
 
    solve(n, m);
 
    return 0;
}
