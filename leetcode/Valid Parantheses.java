import java.util.*;

// note: this can be solved using hashMaps, where you can put the opening bracket as the key and the closing as the value, this way it will be much easier to add more types of brackets without touching logic code :D, but for the purpose of this problem, I will just stick to the solution below

class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        
        for(int i =0; i < s.length(); i++){
            char c = s.charAt(i);
            if(c=='(' || c=='{' || c=='[')
                st.push(c);
            else {
                if(c==')'){
                    if(st.isEmpty() || st.peek() != '(')
                        return false;
                } else if(c=='}'){
                    if(st.isEmpty() || st.peek() != '{')
                        return false;
                } else if(c==']'){
                    if(st.isEmpty() || st.peek() != '[')
                        return false;
                }
                st.pop();
            }
        }
        return st.isEmpty();
    }
}
