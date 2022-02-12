/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "x,";
        }
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }
    
    TreeNode* getDeserializedTree(queue<int>& q) {
        if (q.empty()) {
            return NULL;
        }
        int first = q.front();
        q.pop();
        if (first == INT_MIN) {
            return NULL;
        }
        TreeNode* root = new TreeNode(first);
        root->left = getDeserializedTree(q);
        root->right = getDeserializedTree(q);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<int> q;
        string node = "";
        int n = data.size();
        for (int i = 0; i < n; i++) {
            char c = data[i];
            if (c == ',') {
                if (node == "x") {
                    q.push(INT_MIN);
                } else {
                    q.push(stoi(node));
                }
                node.clear();
            } else {
                node += c;
            }
        }
        return getDeserializedTree(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
