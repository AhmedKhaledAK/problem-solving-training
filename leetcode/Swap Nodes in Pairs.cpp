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
    ListNode* swapPairs(ListNode* head) {
        stack<ListNode*> swapstack;
        ListNode* dummy = NULL;
        ListNode* node = head;
        
        int cnt = 0;
        
        while (node != NULL) {
            cnt++;
            swapstack.push(node);
            if (node->next == NULL &&  cnt % 2 != 0) {
                dummy = node;
                swapstack.pop();
            }
            node = node->next;
        }
        
        while (!swapstack.empty()) {
            ListNode* n1 = swapstack.top();
            swapstack.pop();
            ListNode* n2 = swapstack.top();
            swapstack.pop();
            
            n2->next = dummy;
            n1->next = n2;
            
            dummy = n1;
            
            if (swapstack.empty()) {
                head = n1;
            }
        }
        return head;
    }
};
