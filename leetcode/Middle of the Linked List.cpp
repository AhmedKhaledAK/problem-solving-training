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
    ListNode* middleNode(ListNode* head) {
        
        ListNode *one = head;
        ListNode *two = head;
        
        while (two != NULL && two->next != NULL) {
            two = two->next->next;
            one = one->next;
        }
        
        return one;
        
    }
};
