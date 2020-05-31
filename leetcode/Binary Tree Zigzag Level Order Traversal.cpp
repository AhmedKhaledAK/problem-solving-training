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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if (root == NULL) {
            return ans;
        }
        
        stack<TreeNode*> currentlvl, nextlvl;
        vector<int> v;
        currentlvl.push(root);
        int lefttoright = true;
        while (!currentlvl.empty()) {
            TreeNode* node = currentlvl.top();
            currentlvl.pop();
            v.push_back(node->val);
            if (lefttoright) {
                if (node->left) {
                    nextlvl.push(node->left);
                }
                if (node->right) {
                    nextlvl.push(node->right);
                }
            } else {
                if (node->right) {
                    nextlvl.push(node->right);
                }
                if (node->left) {
                    nextlvl.push(node->left);
                }
            }
            
            if (currentlvl.empty()) {
                ans.push_back(v);
                v.clear();
                swap(currentlvl, nextlvl);
                lefttoright = !lefttoright;
            }
        }
        
        return ans;
    }
};
