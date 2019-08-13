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

vector<vector<int>> adj_list;
const int N = 1e5;
bool visited[N];
int cnt = 0;

void dfs(int i){
    visited[i] = true;
    cnt++;
    for(int j = 0; j < adj_list[i].size(); j++){
        int e = adj_list[i][j];
        if(!visited[e])
            dfs(e);
    }
}

int main() {

    int n,m;
    cin >> n >> m;
    adj_list = vector<vector<int>> (n);

    for(int i =0; i < m; i++){
        int s,d;
        cin >> s >> d;
        adj_list[s-1].push_back(d-1);
        adj_list[d-1].push_back(s-1);
    }

    if(m != n-1)
        cout << "NO";
    else{
        dfs(0);
        if(cnt == n)
            cout << "YES";
        else
            cout << "NO";
    }


    return 0;
}

