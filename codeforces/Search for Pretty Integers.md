```cpp
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

int solve(int n, int m, map<int,int> mlo, map<int,int>mlt){
    int d;
    bool flago = false, flagt = false;
    for(int i = 1; i<=99; i++){
        int n = i;
        do{
            d=n%10;
            n=n/10;
            if(d != 0 && d == mlo[d])
                flago=true;

            if(d != 0 && d == mlt[d])
                flagt=true;

            if(flago && flagt)
                return i;

        }while(n>0);
        flago = flagt = false;
    }
    return 1;
}

int main() {

    map<int,int> mlo;
    map<int,int>mlt;

    int n,m;
    cin >> n >> m;

    for(int i=0; i < n; i++){
        int in;
        cin >> in;
        mlo[in] = in;
    }

    for(int i=0; i < m; i++){
        int in;
        cin >> in;
        mlt[in] = in;
    }

    cout<< solve(n,m,mlo,mlt);

    return 0;
}
```

