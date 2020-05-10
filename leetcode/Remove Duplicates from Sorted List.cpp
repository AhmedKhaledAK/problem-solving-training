/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            return head;
        }
        ListNode* node = head;
        ListNode* prev = new struct ListNode(INT_MIN);
        while (node != NULL) {
            ListNode* nxt = node->next;
            if (node->val == prev->val) {
                node->next = NULL;
                prev->next = nxt;
            } else {
                prev = node;
            }
            node = nxt;
        }
        return head;
    }
};
