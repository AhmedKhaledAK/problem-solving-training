/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* savior = new struct ListNode(0);
        savior->next = head;
        ListNode* slow = savior;
        ListNode* fast = savior;
        
        for (int i =0; i <= n; i++) 
            fast = fast->next;
        
        while (fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return savior->next;
    }
};
