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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            return head;
        }
        ListNode *curr, *rev_start, *prev_start, *rev_end, *next_end;
        curr = head;
        int i = 1;
        while (curr != NULL && i <= n) {
            if (i < m) {
                prev_start = curr;
            }
            if (i == m) {
                rev_start = curr;
            }
            if (i == n) {
                rev_end = curr;
                next_end = curr->next;
            }
            curr = curr->next;
            i++;
        }
        rev_end->next = NULL;
        rev_end = reverse(rev_start);
        if (prev_start != NULL) {
            prev_start->next = rev_end;
        } else {
            head = rev_end;
        }
        rev_start->next = next_end;
        return head;
    }
    
    ListNode* reverse (ListNode* head) {
        ListNode* curr = head, *nxt, *prev;
        while (curr != NULL) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    
    
};
