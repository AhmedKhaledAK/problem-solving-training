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
    ListNode *detectCycle(ListNode *head) {
        ListNode *curr = head;
        
        while (true) {
            if (!curr) {
                break;
            }
            if (curr->val == 10e6) {
                return curr;
            }
            curr->val = 10e6;
            curr = curr->next;
        }
        return NULL;
    }
};
