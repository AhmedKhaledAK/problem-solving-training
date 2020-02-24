#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

bool ismgc(vector<int> v){
    int mat[3][3];

    for (int i = 0; i < 3; ++i)  
        for (int j = 0; j < 3; ++j)  
            mat[i][j] = v[3 * i + j]; 

    int sum = 0,temp=0;
    for(int i =0; i < 3; i++)
        sum+=mat[0][i];
    
    for(int i =1; i < 3; i++){
        temp=0;
        for(int j =0; j < 3; j++){
            temp+=mat[i][j];
        }
        if(temp!=sum) return 0;
    }

    for(int i=0; i < 3; i++){
        temp=0;
        for(int j =0; j < 3; j++){
            temp+=mat[j][i];
        }
        if(temp!=sum) return 0;
    }

    temp=0;
    for(int i =0; i < 3; i++){
        temp+=mat[i][i];
    }
    if(temp!=sum) return 0;
    temp = 0; 
    for (int i = 0; i < 3; i++) 
        temp += mat[2 - i][i]; 

    return temp != sum ? 0 : 1;
}

void allmgcsqrs(vector< vector <int> >& msqrs){
    vector<int> perm(9);

    // must initialize for nect_permutation to work
    for(int i = 0; i < 9; i++){
        perm[i] = i+1; /* from 1 to 10, for next_permutation to work correctly */
    }

    do{
        if(ismgc(perm)){
            msqrs.push_back(perm);
        }
    }while(next_permutation(perm.begin(), perm.end()));

}

int diff(vector<int>v, vector<int> v1){
    int ans = 0;
    for(int i =0; i < 9;i++){
        ans += abs(v[i]-v1[i]);
    }
    return ans;
}

int getmindiff(vector<int> v){
    vector< vector <int> > msqrs;
    allmgcsqrs(msqrs);
    
    int ans = diff(v,msqrs[0]);
    for(int i =1; i < msqrs.size(); i++){
        ans = min(ans, diff(v,msqrs[i]));
    }
    return ans;
}


// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {

    vector<int> ss;

    for(int i =0; i < 3; i++)
        for(int j =0; j < 3; j++)
            ss.push_back(s[i][j]);

    return getmindiff(ss);

}
