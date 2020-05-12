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
    ListNode* partition(ListNode* head, int x) {
        ListNode* curr = head;
        ListNode* node = new struct ListNode(INT_MIN);
        ListNode* newHead = node;
        while (curr != NULL) {
            if (curr->val < x) {
                node->next = new struct ListNode(curr->val);
                node = node->next;
            }
            curr = curr->next;
        }
        curr = head;
        while (curr != NULL) {
            if (curr->val >= x) {
                node->next = new struct ListNode(curr->val);
                node = node->next;
            }
            curr = curr->next;
        }
        return newHead->next;
    }
};
