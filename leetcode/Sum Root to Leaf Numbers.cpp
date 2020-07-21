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
    int sumNumbers(TreeNode* root) {
        if (!root) {
            return 0;
        }
        string number;
        vector<string> numbers;
        solve(root, number, numbers);
        int ans = 0;
        for (int i = 0; i < (int) numbers.size(); i++) {
            ans += stoi(numbers[i]);
        }
        return ans;
    }
    
    void solve(TreeNode* node, string& num, vector<string>& nums) {
        if (!node) {
            return;
        }
        num += to_string(node->val);
        if (!node->left && !node->right) {
            nums.push_back(num);
            num.pop_back();
            return;
        }
        solve(node->left, num, nums);
        solve(node->right, num, nums);
        num.pop_back();
    }
};
