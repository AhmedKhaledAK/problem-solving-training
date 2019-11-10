class Solution {
public:
    int myAtoi(string str) {
        int i =0, isneg=0, ans=0, eqn=0;
        while(str[i] == ' ')
            i++;
        
        if((str[i] != '-' && str[i] != '+') && (str[i] > '9' || str[i] < '0')) 
            return 0;
        
        if(str[i] == '-') {
            i++;
            isneg=1;
        } else if(str[i] == '+') i++;
        
        while(i < str.length() && (str[i] >= 48 && str[i] <= 57)){
            if(eqn > INT_MAX - str[i]+48) {
                if(isneg){
                    return INT_MIN;
                } else return INT_MAX;
            }
            eqn+=(str[i++]-48);
            ans = eqn;
            if(ans > INT_MAX/10) {
                if(i == str.length() || (str[i] < 48 || str[i] > 57)) break;
                if(isneg){
                    return INT_MIN;
                } else return INT_MAX;
            }
            eqn*=10;
        } 
    
        if(isneg) {
            ans*=-1;
        }
        return ans;
    }
};
