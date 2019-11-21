#include <iostream>
#include<bits/stdc++.h>
 
#define array_size(a) (sizeof(a)/sizeof(a[0]))
#define lpi(n) for(int i=0; i<n; i++)
#define lpiv(v,n) for(int i=v; i<n; i++)
#define lpj(n) for(int j=0; j<n; j++)
#define iii pair<int,pair<int,int>>
#define ii pair<int,int>
 
using namespace std;
 
typedef long long ll;
 
map<int, bool> isinq;
 
int main(int argc, const char * argv[]) {
    
    int n,k,id,cnt=0;
    cin >> n >> k;
    deque<int> dq;
    
    lpi(n){
        cin >> id;
        if(isinq[id] == false){
            isinq[id] = true;
            cnt++;
            if(cnt > k){
                isinq[dq.back()] = false;
                dq.pop_back();
                cnt--;
            }
            dq.push_front(id);
        }
    }
    cout << dq.size() << endl;
    auto it = dq.begin();
    for(it = dq.begin(); it != dq.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
