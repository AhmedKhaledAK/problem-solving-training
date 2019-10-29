#include <iostream>
#include<bits/stdc++.h>

#define array_size(a) (sizeof(a)/sizeof(a[0]))
#define lpi(n) for(int i=0; i<n; i++)
#define lpiv(v,n) for(int i=v; i<n; i++)
#define lpj(n) for(int j=0; j<n; j++)
#define iii pair<int,pair<int,int>>
#define ii pair<int,int>

using namespace std;

bool ar[50][50];
bool b[50][50];

typedef long long ll;

int main(int argc, const char * argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    
   
    
    int n,m,x,ni,nj,k=0,zero=0;
    cin >> n >> m;
    
    vector<ii> vii;
    
    lpi(n){
        lpj(m){
            cin >> ar[i][j];
            if(!ar[i][j])zero++;
        }
    }
    
    if(zero == n*m){
        cout << 0 << endl;
        return 0;
    }
    
    lpi(n-1){
        lpj(m-1){
            if(ar[i][j] == 1 && ar[i][j + 1] == 1 && ar[i + 1][j] == 1 && ar[i + 1][j + 1] == 1){
                b[i][j] = 1;
                b[i][j + 1] = 1;
                b[i + 1][j] = 1;
                b[i + 1][j + 1] = 1;
                vii.push_back(make_pair(i+1,j+1));
                k++;
            }
        }
    }
    
    
    lpi(n){
        lpj(m){
            if(ar[i][j] != b[i][j]){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    cout << k << endl;
    
    lpi(k)
        cout << vii[i].first << " " << vii[i].second << endl;
    
    return 0;
}

