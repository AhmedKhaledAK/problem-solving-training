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
int color[N];
vector< vector<int> > adj;
ll r,b;

void bfs(int src){
    queue<int> q;
    q.push(src);
    color[src] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        if(color[u] == 1)
            r++;
        else
            b++;

        for(int i =0; i < adj[u].size(); i++){
            int el = adj[u][i];

            if(color[el] == 0){
                if(color[u] == 1)
                    color[el] = 2;
                else
                    color[el] = 1;
                q.push(el);
            }
        }
    }
}

ll solve(int n, int s){
    bfs(s);
    // beware of this line: r,b MUST be bigger than "int" even if the return value of the function is ll. If they're ints, the result of the multiplication will be int also and it will cause "signed integer overflow error"
    return r*b - (n-1);
}


int main(int argc, const char * argv[]) {

    int n;
    cin >> n;
    adj = vector< vector<int> > (n);
    int s;
    for(int i =0; i < n-1; i++){
        int d;
        cin >> s >> d;
        adj[s-1].push_back(d-1);
        adj[d-1].push_back(s-1);
    }

    cout << solve(n,s-1);

    return 0;
}

