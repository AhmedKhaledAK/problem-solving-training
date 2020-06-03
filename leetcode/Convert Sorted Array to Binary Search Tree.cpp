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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, (int) nums.size() - 1);
    }
    
    TreeNode* helper(vector<int>& nums, int st, int end) {
        if (st > end) {
            return NULL;
        }
        int mid = st + (end - st) / 2;
        TreeNode* root = new struct TreeNode(nums[mid]);
        
        if (st == end) {
            return root;
        }
        
        root->left = helper(nums, st, mid - 1);
        root->right = helper(nums, mid + 1, end);
        
        return root;
    }
};
