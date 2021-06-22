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
        if (!headA || !headB) return NULL;
        int sizeA, sizeB;
        sizeA = sizeB = 0;
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != NULL) {
            a = a->next;
            sizeA++;
        }
        while(b != NULL) {
            b = b->next;
            sizeB++;
        }
        ListNode* startA = headA;
        ListNode* startB = headB;
        
        int diff = abs(sizeA - sizeB);
        for (int i = 0; i < diff; i++) {
            if (sizeA > sizeB) {
                startA = startA->next;
            } else {
                startB = startB->next;
            }
        }
        while (startA && startB) {
            if (startA == startB) return startA;
            startA = startA->next;
            startB = startB->next;
        }
        return NULL;
    }
};