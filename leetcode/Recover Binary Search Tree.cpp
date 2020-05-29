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
    void recoverTree(TreeNode* root) {
        TreeNode *first, *mid, *last, *prev;
        first = mid = last = prev = NULL;
        
        traverse(root, &first, &mid, &last, &prev);
        
        if (first && last) {
            swap(&(first->val), &(last->val));
        } else if (first && mid) {
            swap(&(first->val), &(mid->val));
        }
        
    }
    
    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    
    void traverse(TreeNode* node, TreeNode** first, TreeNode** mid, TreeNode** last, TreeNode** prev) {
        if (node != NULL) {
            traverse(node->left, first, mid, last, prev);
            if (*prev != NULL && node->val < (*prev)->val) {
                if (*first == NULL) {
                    *first = *prev;
                    *mid = node;
                } else if (*last == NULL) {
                    *last = node;
                }
            }
            *prev = node;
            traverse(node->right, first, mid, last, prev);
        }
    }
};
