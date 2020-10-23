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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * t = new ListNode(0);
        t->next = head;
        ListNode * current = head;
        ListNode * prev = t;
        
        while(current != nullptr) {
            if(current->val == val) {
                prev->next = current->next;
            }else {
                prev = current;
            } 
            current = current->next;
        }
        return t->next;
    }
};
