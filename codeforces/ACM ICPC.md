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
const int N = 6;

int main() {

    int arr[N];
    int sum_two=0;
    bool flag = false;

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    for(int i =0; i < N; i++){
        for (int j = i+1; j < N; ++j) {
            for(int k = 0; k < N; k++){
                if(k == i || k == j) continue;
                int sum_one = arr[i] + arr[j] + arr[k];
                for(int s = 0; s < N; s++){
                    if(s == i || s == j || s == k) continue;
                    sum_two += arr[s];
                }
                if(sum_one == sum_two){
                    cout << "YES";
                    flag = true;
                    break;
                }else
                    sum_two = 0;
            }
            if(flag)break;
        }
        if(flag) break;
    }

    if(!flag) cout << "NO";

    return 0;
}
```

