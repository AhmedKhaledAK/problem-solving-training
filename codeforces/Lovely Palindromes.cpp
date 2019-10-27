#include <iostream>
#include<bits/stdc++.h>

#define array_size(a) (sizeof(a)/sizeof(a[0]))
#define lpi(n) for(int i=0; i<n; i++)
#define lpi1(n) for(int i=1; i<n; i++)
#define lpj(n) for(int j=0; j<n; j++)
#define iii pair<int,pair<int,int>>
#define ii pair<int,int>

using namespace std;

typedef long long ll;

int main(int argc, const char * argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    string s;
    cin >> s;

    if(s.length() == 1) {
        cout << s << s;
        return 0;
    }

    cout<<s;

    int i =0, j = s.length()-1;

    while(i < j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }

    cout << s;

    return 0;
}

