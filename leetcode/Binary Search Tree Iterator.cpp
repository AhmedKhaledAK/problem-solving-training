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
class BSTIterator {
    
private:
    vector<int> nums;
    int idx;
    
    void convertToArray(TreeNode *root) {
        if (!root) {
            return;
        }
        convertToArray(root->left);
        nums.push_back(root->val);
        convertToArray(root->right);
    }
    
public:
    BSTIterator(TreeNode* root) {
        convertToArray(root);
        idx = 0;
    }
    
    /** @return the next smallest number */
    int next() {
        return nums[idx++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return idx < nums.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
