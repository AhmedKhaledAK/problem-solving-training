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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int s1 = get_size(l1), s2 = get_size(l2);
        ListNode *h1 = l1, *h2 = l2;
        if (s1 > s2) {
            h1 = get_first(l1, s1 - s2);
        } else if (s1 < s2) {
            h2 = get_first(l2, s2 - s1);
        }
        
        int carry = 0;
        ListNode* ans = NULL;
        
        ans = solve(h1, h2, carry);
        
        int diff = -1;
        if (s1 > s2) {
            diff = s1 - s2 - 1;
            h1 = get_first(l1, 0);
        } else if (s1 < s2) {
            diff = s2 - s1 - 1;
            h1 = get_first(l2, 0);
        }
        ListNode* anss = ans;
        if (diff != -1) {
            ListNode* ans2 = add(h1, diff, carry);
            ListNode* temp = ans2;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ans;
            anss = ans2;
        }
        
        if (carry != 0) {
            anss = new struct ListNode(carry, anss);
        }
        
        return anss;
    }
    
    ListNode* add(ListNode* l, int& diff, int& carry) {
        if (diff == 0) {
            ListNode* node = new struct ListNode((l->val + carry) % 10);
            carry = (l->val + carry) / 10;
            return node;
        }
        ListNode* n = add(l->next, --diff, carry);
        ListNode* node = new struct ListNode((l->val + carry) % 10, n);
        carry = (l->val + carry) / 10;
        return node;
    }
    
    ListNode* solve(ListNode* l1, ListNode* l2, int& carry) {
        if (l1->next == NULL && l2->next == NULL) {
            ListNode* node = new struct ListNode((l1->val + l2->val) % 10);
            carry = (l1->val + l2->val) / 10;
            return node;
        }
        ListNode* n = solve(l1->next, l2->next, carry);
        
        ListNode* node = new struct ListNode((l1->val + l2->val + carry) % 10, n);
        carry = (l1->val + l2->val + carry) / 10;
        return node;
    } 
    
    ListNode* get_first(ListNode* l, int diff) {
        ListNode* curr = l;
        while (diff != 0) {
            curr = curr->next;
            diff--;
        }
        return curr;
    }
    
    int get_size(ListNode* l) {
        ListNode* curr = l;
        int s = 0;
        while (curr != NULL) {
            curr = curr->next;
            s++;
        }
        return s;
    }
};
