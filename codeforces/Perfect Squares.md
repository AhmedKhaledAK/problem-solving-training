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

int main() {

    int n;
    double max = INT_MIN;
    cin >> n;
    for(int i = 0; i < n; i++){
        double in, sr;
        cin >> in;
        sr = sqrt(in);
        if(floor(sr) != sr && in > max)
            max = in;
    }

    cout << (int) max;

    return 0;
