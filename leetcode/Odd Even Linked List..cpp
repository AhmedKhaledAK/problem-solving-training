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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            return head;
        }
        ListNode* first_even = head->next;
        ListNode* curr = head;
        int i = 1;  // even or odd?
        while (curr != NULL) {
            ListNode* nxt = curr->next;
            if (nxt != NULL) {
                curr->next = nxt->next;
            }
            if (curr->next == NULL && i % 2 != 0) {
                curr->next = first_even;
            }
            curr = nxt;
            i++;
        }
        return head;
    }
};
