class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : nodes(26, NULL), isWord(false){
    }
    vector<TrieNode*> nodes;
    bool isWord;
    //char ch;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for(char ch : word)
        {
            
            if(node -> nodes[ch - 'a'] == NULL)
            {
                node -> nodes[ch - 'a'] = new TrieNode();
            }
            node = node -> nodes[ch - 'a'];
        }
        
        node -> isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for(char ch : word)
        {
            if(node -> nodes[ch - 'a'] == NULL)
                return false;
            node = node -> nodes[ch - 'a'];
        }
        
        return node -> isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char ch : prefix)
        {
            if(node -> nodes[ch - 'a'] == NULL)
                return false;
            node = node -> nodes[ch - 'a'];
        }
        
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */