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
    bool hasCycle(ListNode *head) {
        ListNode *curr = head;
        
        while (true) {
            if (!curr) {
                break;
            }
            if (curr->val == 10e6) {
                return true;
            }
            curr->val = 10e6;
            curr = curr->next;
        }
        return false;
    }
};
