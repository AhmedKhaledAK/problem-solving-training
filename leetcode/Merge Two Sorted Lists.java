import java.util.*;

/*public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
 }*/
 
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode mergedList = new ListNode(Integer.MIN_VALUE);
        ListNode backupList = mergedList;
        while(l1 != null && l2 != null){
            if(l1.val >= l2.val){
                mergedList.next = new ListNode(l2.val);
                l2=l2.next;
            } else {
                mergedList.next = new ListNode(l1.val);
                l1=l1.next;
            }
            mergedList=mergedList.next;
        }
        while(l1 != null){
            mergedList.next = new ListNode(l1.val);
            mergedList=mergedList.next;
            l1=l1.next;
        }
        while(l2 != null){
            mergedList.next = new ListNode(l2.val);
            mergedList=mergedList.next;
            l2=l2.next;
        }
        return backupList.next;
    }
}
