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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *currA = headA, *currB = headB;
        
        unordered_set<ListNode*> st;
        
        while (currA) {
            st.insert(currA);
            currA = currA->next;
        }
        
        while (currB) {
            if (st.count(currB) != 0) {
                return currB;
            }
            currB = currB->next;
        }
        return NULL;
    }
};
