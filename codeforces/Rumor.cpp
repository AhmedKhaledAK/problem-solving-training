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

#include <bits/stdc++.h>
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#define lp(n) for(int i=0; i<n; i++)

using namespace std;

typedef long long ll;

const int N = 1e5;
bool visited[N];
int c[N];
vector< vector<int> > adj;
ll minGlobal = LONG_MAX;


void dfs(int i){
    visited[i] = true;
    if(c[i] < minGlobal)
        minGlobal = c[i];
    for(int j = 0; j < adj[i].size(); j++){
        int el = adj[i][j];
        if(!visited[el])
            dfs(el);
    }
}

ll solve(int n, int m){
    ll minAns = 0;
    if(m == 0)
        lp(n)
            minAns+=c[i];
    else {
        lp(n){
            if(!visited[i]){
                minGlobal = c[i];
                dfs(i);
                minAns += minGlobal;
            }
        }
    }
    return minAns;
}

int main(int argc, const char * argv[]) {


    int n, m;
    cin >> n >> m;
    adj = vector< vector<int> > (n);

    lp(n)
        cin >> c[i];

    lp(m){
        int s,d;
        cin >> s >> d;
        adj[s-1].push_back(d-1);
        adj[d-1].push_back(s-1);
    }

    cout << solve(n, m);

    return 0;
}

