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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* curr = head;
        int size = 0;
        while (curr != NULL) {
            curr = curr->next;
            size++;
        }
        return helper(head, 0, size - 1);
    }
    
    TreeNode* helper(ListNode* list, int st, int end) {
        if (st > end) {
            return NULL;
        }
        int mid = st + (end - st) / 2;
        int val = getMid(list, mid);
        TreeNode* root = new struct TreeNode(val);
        
        if (st == end) {
            return root;
        }
        
        root->left = helper(list, st, mid - 1);
        root->right = helper(list, mid + 1, end);
        
        return root;
    }
    
    int getMid(ListNode* head, int mid) {
        ListNode* curr = head;
        int i = 0;
        while (curr != NULL && i < mid) {
            curr = curr->next;
            i++;
        }
        return curr->val;
    }
};
