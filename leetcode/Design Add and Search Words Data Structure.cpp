class TrieNode {
  public:
    vector<TrieNode*> children;
    bool isLeaf;
    TrieNode() : children(26) {
        isLeaf = false;
    }
};


class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        int n = word.size();
        TrieNode* node = root;
        for (int i = 0; i < n; i++) {
            int idx = word[i] - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isLeaf = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        return dfs(word, 0, node);
    }
    
    bool dfs(string word, int idx, TrieNode* node) {
        if (idx == word.size()) {
            return node->isLeaf;
        }
        if (word[idx] != '.') {
            if (!node->children[word[idx] - 'a']) {
                return false;
            }
            return dfs(word, idx + 1, node->children[word[idx] - 'a']);
        }
        bool res = false;
        for (auto child : node->children) {
            if (!child) {
                continue;
            }
            res = res || dfs(word, idx + 1, child);
        }
        return res;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
