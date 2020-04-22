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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;
        ListNode* h = head;
        while (h != NULL) {
            size++;
            h = h->next;
        }
        if (size == 1) {
            return head;
        }
        h = head;
        ListNode* last_first = NULL;
        ListNode* dumm = NULL;
        int cnt = 1;
        bool times = 0;
        while (cnt < size) {
            int count = 1;
            ListNode* first = h;
            while (count < k && h != NULL) {
                h = h->next;
                count++;
                cnt++;
            }
            if (times == 0 && h != NULL){
                dumm = h;
                times = 1;
            }
            if (count != k || h == NULL) {   // we are done
                return dumm;
            }
            ListNode* end = h->next;
            ListNode* prev = h->next;
            ListNode* nxt = NULL;
            ListNode* curr = first;
            
            while (curr != end) {
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt; 
            }
            if (last_first != NULL) {
                last_first->next = prev;
            }
            h = curr;
            cnt++;
            last_first = first;
        }
        return dumm;
    }
};
