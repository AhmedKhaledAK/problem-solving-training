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
#define ii pair<int,int>

using namespace std;

typedef long long ll;

const int N = 2000;

char mat[N][N];

int solve(int n, int m, int k){

    int cnt =0, sol=0, seats =0, x;
    for(int i =0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j]=='*') continue;
            for(x = j; x < m; x++){
                if(mat[i][x] == '.'){
                    if(++cnt>=k){
                        sol-=seats;
                        seats=cnt-k+1;
                        sol+=seats;
                    }
                } else
                    break;
            }
            cnt=0;
            seats=0;
            j=x;
        }
    }

    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            if(mat[i][j]=='*') continue;
            for(x = i; x <n; x++){
                if(mat[x][j]=='.'){
                    if(++cnt>=k){
                        sol-=seats;
                        seats=cnt-k+1;
                        sol+=seats;
                    }
                } else
                    break;
            }
            cnt=0;
            seats=0;
            i=x;
        }
    }

    return k==1 ? sol/2 : sol;
}

int main(int argc, const char * argv[]) {

    int n,m,k;
    scanf("%d%d%d", &n,&m,&k);

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j =0; j < m; j++){
            mat[i][j] = s[j];
        }
    }

    printf("%d", solve(n,m,k));

    return 0;
}

