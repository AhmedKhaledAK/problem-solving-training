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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* dummy = head, *one = head, *two = head;
        int size = 0, rk, i;
        while (dummy != NULL) {
            size++;
            dummy = dummy->next;
        }
        if (size == 0) {
            return NULL;
        }
        rk = k % size;
        if (rk == 0) {
            return head;
        }
        i = 0;
        while (i < rk && two->next != NULL) {
            two = two->next;
            i++;
        }
        i = 0;
        while (i < rk && two->next != NULL) {
            one = one->next;
            two = two->next;
        }
        
        two->next = head;
        head = one->next;
        one->next = NULL;
        
        return head;
    }
};
