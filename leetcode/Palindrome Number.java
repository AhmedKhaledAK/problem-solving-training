class Solution {
    public boolean isPalindrome(int x) {
        int ans=0, num=x;
        if(x<0 || (x%10 == 0 && x!=0))
            return false;
        while(x>ans){
            int d = x%10;
            ans = ans * 10 +d;
            x/=10;
        }
        return x==ans || x==ans/10;
    }
}
