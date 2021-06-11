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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !(head->next)) return head;
        ListNode* curr = head;
        ListNode* next = curr->next;
        ListNode* prev = NULL;
        ListNode* ans = next;
        while (curr != NULL && next != NULL) {
            curr->next = next->next;
            next->next = curr;
            if (prev) {
                prev->next = next;
            }
            if (curr->next == NULL) {
                break;
            }
            prev = curr;
            curr = curr->next;
            next = curr->next;
        }
        return ans;
    }
};