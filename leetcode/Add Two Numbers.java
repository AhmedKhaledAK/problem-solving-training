/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ansList = new ListNode(-1);
        ListNode backupList = ansList;
        
        int ans=0,rem=0;
        
        while(l1 != null && l2 != null){
            ans = l1.val + l2.val + rem;
            rem = solve(ansList, ans);
            l1=l1.next;
            l2=l2.next;
            ansList=ansList.next;
        }
        
        while(l1!=null){
            ans = l1.val+rem;
            rem = solve(ansList, ans);
            l1=l1.next;
            ansList=ansList.next;
        }
        
        while(l2!=null){
            ans = l2.val+rem;
            rem = solve(ansList, ans);
            l2=l2.next;
            ansList=ansList.next;
        }
        
        if(rem>0){
            ansList.next = new ListNode(rem);
        }
        
        return backupList.next;
        
    }
    
    public int solve(ListNode ansList, int ans){
        int rem=0;
        if(ans >= 10){
            rem = ans/10;
            ansList.next = new ListNode(ans%10);
        } else {
            rem = 0;
            ansList.next = new ListNode(ans);
        }
        return rem;
    }
}
