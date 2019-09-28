class Solution {
    public boolean isSubsequence(String s, String t) {
        int i = 0, j=0;
        while(j <= t.length()-1 && i <= s.length()-1){
            if(s.charAt(i) == t.charAt(j)){
                i++;
                j++;
            } else {
                j++;
            }
        }
        return i==s.length() ? true : false;
    }
}
