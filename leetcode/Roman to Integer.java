import java.util.*;

class Solution {
    public int romanToInt(String s) {
        HashMap<Character, Integer> hm = new HashMap<>();
        hm.put('I',1);
        hm.put('V',5);
        hm.put('X',10);
        hm.put('L',50);
        hm.put('C',100);
        hm.put('D',500);
        hm.put('M',1000);
        
        int ans=0;
        
        for(int i =0; i < s.length(); i++){
            char c = s.charAt(i);
            if(i==s.length()-1){
                ans+=hm.get(c);
                break;
            }
             if( (c=='I' && (s.charAt(i+1) != 'V' && s.charAt(i+1) != 'X')) || (c=='X' && (s.charAt(i+1) != 'L' && s.charAt(i+1) != 'C')) || (c=='C' && (s.charAt(i+1) != 'D' && s.charAt(i+1) != 'M')) ){
                ans+=hm.get(c);
            }else if(c == 'V' || c == 'L' || c == 'D' || c == 'M')
                ans+=hm.get(c);
            else {
                if((c=='I' || c=='X' || c=='C')){
                    ans+=(hm.get(s.charAt(i+1))-hm.get(c));
                    i++;
                }
            }
        }
        return ans;
    }
}
