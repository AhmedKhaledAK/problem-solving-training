import java.util.*;

class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> ansList = new LinkedList<>();
        if(digits.length() == 0) return ansList;
        HashMap< Character, ArrayList<Character> > hm = new HashMap<>();
        fillHashMap(hm);
        
        bt(hm, ansList, digits, "", 0);
        return ansList;
    }
    
    public void bt(HashMap< Character, ArrayList<Character> > hm, List<String> ansList, String digits, String s,
                   int i){
        if(s.length() == digits.length()){
            ansList.add(s);
            return;
        } 
        ArrayList<Character> al = hm.get(digits.charAt(i));
        i++;
        for(int j=0; j < al.size(); j++){
            bt(hm, ansList, digits, s+al.get(j), i);
            if(s.length() != 0) s.substring(0,s.length()-1);
        }
    }
    
    public void fillHashMap(HashMap< Character, ArrayList<Character> > hm){
        hm.put('2', new ArrayList<>(Arrays.asList('a','b','c')));
        hm.put('3', new ArrayList<>(Arrays.asList('d','e','f')));
        hm.put('4', new ArrayList<>(Arrays.asList('g','h','i')));
        hm.put('5', new ArrayList<>(Arrays.asList('j','k','l')));
        hm.put('6', new ArrayList<>(Arrays.asList('m','n','o')));
        hm.put('7', new ArrayList<>(Arrays.asList('p','q','r','s')));
        hm.put('8', new ArrayList<>(Arrays.asList('t','u','v')));
        hm.put('9', new ArrayList<>(Arrays.asList('w','x','y','z')));
    }
}
