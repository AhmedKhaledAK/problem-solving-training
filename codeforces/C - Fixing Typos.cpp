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

const int N = 2e5;

bool no_print[N];

void solve(string s){
    bool dt=false;
    for(int i = 1; i < s.length(); i++){

        if(i!=1 && s[i] == s[i-1] && s[i] == s[i-2])
            no_print[i]=true;

        else if(s[i] == s[i-1]){
            if(dt==true && s[i-2] != s[i-3])
                dt=false;

            if(dt==true){
                no_print[i]=true;
                dt=false;
            } else
                dt=true;
        }
    }

    for(int i =0; i < s.length(); i++){
        if(!no_print[i])
            cout << s[i];
    }

}

int main(int argc, const char * argv[]) {

    string s;
    cin >> s;

    solve(s);
    return 0;
}

