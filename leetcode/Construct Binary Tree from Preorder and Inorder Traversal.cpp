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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preidx = 0;
        return helper(preorder, inorder, 0, inorder.size() - 1, preidx);
    }
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int start, int end, int& preidx) {
        if (start > end) {
            return NULL;
        }
        
        TreeNode* root = new struct TreeNode(preorder[preidx++]);
        
        if (start == end) {
            return root;
        }
        
        int inidx = search(inorder, root->val, start, end);
        
        root->left =helper(preorder, inorder, start, inidx - 1, preidx);
        root->right = helper(preorder, inorder, inidx + 1, end, preidx);
        
        return root;
    }
    
    int search(vector<int>& v, int val, int start, int end) {
        for (int i = start; i < end; i++) {
            if (v[i] == val) { 
                return i;
            }
        }
        return end;
    }
};
