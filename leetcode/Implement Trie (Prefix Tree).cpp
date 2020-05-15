class TrieNode {
public:
    vector<TrieNode*> children;
    bool leaf;
    
    TrieNode() : children(26) {
        this->leaf = false;
    }
};

class Trie {
private:
    TrieNode* root;
    
    bool helper(string word, bool ss) {
        int n = word.length();
        TrieNode* node = root;
        for (int i = 0; i < n; i++) {
            int idx = word[i] - 'a';
            if (node->children[idx] == NULL) {
                return false;
            }
            node = node->children[idx];
        }
        if (ss) {
            return node != NULL && node->leaf;
        }
        return node != NULL;
    }
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.length();
        TrieNode* node = root;
        for (int i = 0; i < n; i++) {
            int idx = word[i] - 'a';
            if (node->children[idx] == NULL) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->leaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return helper(word, true);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return helper(prefix, false);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
