class Solution {
public:
    int nextGreaterElement(int n) 
    {
        string s = to_string(n);
        long long int a =LLONG_MAX;
        do {
           long long int k=stoll(s);
            if(k!=n) { 
                a=min(a,k);
            }
        } 
        while(next_permutation(s.begin(),s.end()));
        if(a>n && a<=INT_MAX) {
            return a;
        }
        return -1;
    }
};