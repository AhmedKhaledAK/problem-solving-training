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

const int N = 1e5;
bool visited[N];
int cnt[N];
vector<vector<int>> adj;

int root = -1;
int val = -1;

void dfs(int i){
    visited[i] = true;
    if(val < cnt[i]){
        root = i;
        val = cnt[i];
    }
    for(int j = 0; j < adj[i].size(); j++){
        int el = adj[i][j];
        if(!visited[el]){
            cnt[el] = cnt[i] + 1;
            dfs(el);
        }
    }
}

int solve(int n){
    dfs(0);
    for(int i =0; i < N; i++){
        visited[i] = false;
        cnt[i]=0;
    }
    dfs(root);
    return val;
}


int main() {

    int n,s,d;
    cin >> n;
    adj = vector<vector<int>>(n);

    for(int i = 0; i < n-1; i++){
        cin >> s >> d;
        adj[s-1].push_back(d-1);
        adj[d-1].push_back(s-1);
    }

    cout << solve(n);

    return 0;
}

