import java.util.*;


// Note: this problem can also be solved using Binary Search which will take the same time complexity as this one used here
// Sort the array, then binary search on the minimum word, if you completed the search successfully, then you have found the LCP ;). If not, then binary search again on the minimum word-1 and so on.

class Solution { 
    public String longestCommonPrefix(String[] strs) {
        
        if(strs.length==0)
            return "";
        if(strs.length==1)
            return strs[0];
        
        Arrays.sort(strs);
        
        String first = strs[0];
        String last = strs[strs.length-1];
        
        StringBuilder sb = new StringBuilder("");
        for(int i = 0; i < first.length(); i++){
            if(first.charAt(i)==last.charAt(i))
                sb.append(first.charAt(i)+"");
            else 
                break;
        }
        return sb.toString();
    }
}
