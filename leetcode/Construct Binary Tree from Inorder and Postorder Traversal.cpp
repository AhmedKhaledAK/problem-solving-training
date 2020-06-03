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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postidx = (int) postorder.size() - 1;
        return helper(inorder, postorder, 0, postidx, postidx);
    }
    
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int start, int end, int& postidx) {
        if (start > end) {
            return NULL;
        }
        
        TreeNode* root = new struct TreeNode(postorder[postidx--]);
        
        if (start == end) {
            return root;
        }
        
        int inidx = search(inorder, start, end, root->val);
        
        root->right = helper(inorder, postorder, inidx + 1, end, postidx);
        root->left = helper(inorder, postorder, start, inidx - 1, postidx);
        
        return root;
    }
    
    int search(vector<int>& v, int st, int e, int el) {
        for (int i = st; i < e; i++) {
            if (v[i] == el) {
                return i;
            }
        }
        return e;
    }
};
