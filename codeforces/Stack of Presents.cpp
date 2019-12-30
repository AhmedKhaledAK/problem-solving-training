#include <iostream>
#include<bits/stdc++.h>
#include <iomanip>
 
#define array_size(a) (sizeof(a)/sizeof(a[0]))
#define lpi(n) for(int i=0; i<n; i++)
#define lpiv(v,n) for(int i=v; i<n; i++)
#define lpj(n) for(int j=0; j<n; j++)
#define iii pair<int,pair<int,int>>
#define ii pair<int,int>
 
using namespace std;
 
typedef long long ll;
 
int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(0);
    
    
    int t,n,m,x,y;
    ll sout=0,cnt=0,sum=0, xcnt=0;
    
    cin >> t;
    
    while(t--){
        cin>>n>>m;
        
        deque<int> deqn,deqm;
        unordered_map<int,bool> out;
        
        lpi(n){
            cin >> y;
            deqn.push_back(y);
        }
        
        lpi(m){
            cin >> x;
            deqm.push_back(x);
        }
        
        while(!deqm.empty()){
            x=deqm.front();
            deqm.pop_front();
            if(sout == 0 || !out[x]){
                if(!out[x] && sout!=0){
                    sum+=sout;
                }
                y=deqn.front();
                while(y!=x){
                    deqn.pop_front();
                    cnt++;
                    sout++;
                    out[y] = true;
                    y=deqn.front();
                }
                cnt++;
                deqn.pop_front();
                sum+=cnt+sout;
            } else {
                sum+=1;
                out[x]=false;
                sout--;
            }
            cnt=0;
        }
        cout << sum << "\n";
        sout=cnt=sum=xcnt=0;
    }
    return 0;
}
