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
#define loop(n) for(int j=0; j<n; j++)
#define iii pair<int,pair<int,int>>

using namespace std;

typedef long long ll;

const int N = 2000, M = 2000;
int n, m, k;
int row[] = {-1,1,0,0};
int col[] = {0,0,-1,1};
bool visited[N][M];
int sp[N][M];
queue<iii> pq;

bool checkChild(int r, int c, int i, int j){
    return i >= 0 && i <= r - 1 && j >= 0 && j <= c - 1;
}

void bfs(){

    while(!pq.empty()){
        iii pairs=pq.front();
        pq.pop();
        int i = pairs.second.first;
        int j = pairs.second.second;
        int p = pairs.first;

        for(int g =0; g < 4; g++){
            int ni = i+row[g];
            int nj = j+col[g];
            if(checkChild(n,m,ni,nj)){
                if(p+1 < sp[ni][nj]){
                    sp[ni][nj]=p+1;
                    iii pairs2;
                    pairs2.first = sp[ni][nj];
                    pairs2.second.first = ni;
                    pairs2.second.second = nj;
                    pq.push(pairs2);
                }
            }
        }
    }
}

void solve(){

    bfs();

    int ans = INT_MIN;
    int r,c;
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++){
            if(sp[i][j] > ans){
                ans = sp[i][j];
                r=i+1;
                c=j+1;
            }
        }
    }
    printf("%d %d", r,c);
}

int main(int argc, const char * argv[]) {

    //comment these two lines when testing on your machine
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d%d",&n,&m,&k);

    lp(n){
        loop(m){
            sp[i][j] = INT_MAX-1;
        }
    }

    int x,s;
    lp(k){
        scanf("%d%d",&x,&s);
        sp[x-1][s-1] = 0;
        iii pairs;
        pairs.first = sp[x-1][s-1];
        pairs.second.first = x-1;
        pairs.second.second = s-1;
        pq.push(pairs);
    }

    solve();

    return 0;
}

