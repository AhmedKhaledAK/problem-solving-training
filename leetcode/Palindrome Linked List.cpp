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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *prevOfSlow = head;
        ListNode *secondHalf;
        bool ret = true;
        if (head != NULL && head->next != NULL) {
            while (fast && fast->next) {
                prevOfSlow = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            if (fast) {
                slow = slow->next;
            }
            secondHalf = slow; 
            prevOfSlow->next = NULL; 
            reverse(&secondHalf); 
            ret = compareLists(head, secondHalf); 
        }
        return ret;
    }
    
    void reverse(ListNode** head_ref) {  
        ListNode* prev = NULL;  
        ListNode* current = *head_ref;  
        ListNode* next;  
        while (current != NULL) {  
            next = current->next;  
            current->next = prev;  
            prev = current;  
            current = next;  
        }  
        *head_ref = prev;  
    }  
  
    bool compareLists(ListNode* head1, ListNode* head2) {  
        ListNode* temp1 = head1;  
        ListNode* temp2 = head2;  

        while (temp1 && temp2) {  
            if (temp1->val == temp2->val) {  
                temp1 = temp1->next;  
                temp2 = temp2->next;  
            }  
            else
                return 0;  
        }  

        if (temp1 == NULL && temp2 == NULL)  
            return 1;  

        return 0;  
    }  
};
