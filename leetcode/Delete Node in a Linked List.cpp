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
    void deleteNode(ListNode* node) {
        swap(node->next->val, node->val);
        ListNode* nxt = node->next; 
        node->next = nxt->next; 
        nxt->next = NULL;
    }
};
