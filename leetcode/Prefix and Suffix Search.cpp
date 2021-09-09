class TrieNode {
public:
    vector<TrieNode*> children;
    int weight;
    TrieNode() : children(27) {
        this->weight = 0;
    }
};

class WordFilter {
private:
    TrieNode* trie;
public:
    WordFilter(vector<string>& words) {
        trie = new TrieNode();
        for (int weight = 0; weight < words.size(); weight++)
        {
            string word = words[weight] + "{";
            for (int i = 0; i < word.size(); i++)
            {
                TrieNode* cur = trie;
                cur->weight = weight;
                for (int j = i; j < 2 * word.size() - 1; j++)
                {
                    int c = word[j % word.size()] - 'a';
                    if (cur->children[c] == NULL)
                    {
                        cur->children[c] = new TrieNode();
                    }
                    cur = cur->children[c];
                    cur->weight = weight;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        TrieNode* cur = trie;
        for (char letter : (suffix + "{" + prefix))
        {
            if (cur->children[letter - 'a'] == NULL)
            {
                return -1;
            }
            cur = cur->children[letter - 'a'];
        }
        return cur->weight;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
