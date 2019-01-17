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

    TrieNode* root;
};

class Solution {
public:
    int m , n;
    set<string> search(vector<vector<char>>& board, vector<vector<bool>>& visit, int i, int j, TrieNode* root){
        // cout << i << " " << j << endl;
        set<string> vec;
        if(root -> isWord)
        {
            string s = "";
            s += board[i][j];
            vec.insert(s);
        }
        
        if(i - 1 >= 0)
        {
            if(!visit[i-1][j] && root -> nodes[board[i-1][j] - 'a'] != NULL)
            {
                visit[i-1][j] = true;
                set<string> p = search(board,visit,i-1,j,root -> nodes[board[i-1][j] - 'a']);
                for(set<string>::iterator it = p.begin() ; it != p.end() ; ++it)
                {
                    vec.insert(board[i][j ] + *it);
                }
                // vec.insert(p.begin(),p.end());
                
                visit[i-1][j] = false;
            }
        }
        
        if(i + 1 < m)
        {
            if(!visit[i+1][j] && root -> nodes[board[i+1][j] - 'a'] != NULL)
            {
                visit[i+1][j] = true;
                set<string> p = search(board,visit,i+1,j,root -> nodes[board[i+1][j] - 'a']);
                for(set<string>::iterator it = p.begin() ; it != p.end() ; ++it)
                {
                    vec.insert(board[i][j ] + *it);
                }
                // vec.insert(p.begin(),p.end());
                visit[i+1][j] = false;
            }
        }
        
        if(j - 1 >= 0)
        {
            if(!visit[i][j-1] && root -> nodes[board[i][j-1] - 'a'] != NULL)
            {
                visit[i][j-1] = true;
                set<string> p = search(board,visit,i,j-1,root -> nodes[board[i][j-1] - 'a']);
                for(set<string>::iterator it = p.begin() ; it != p.end() ; ++it)
                {
                    vec.insert(board[i][j ] + *it);
                }
                // vec.insert(p.begin(),p.end());
                
                visit[i][j-1] = false;
            }
        }
        
        if(j + 1 < n)
        {
            if(!visit[i][j+1] && root -> nodes[board[i][j+1] - 'a'] != NULL)
            {
                visit[i][j+1] = true;
                set<string> p = search(board,visit,i,j+1,root -> nodes[board[i][j+1] - 'a']);
                for(set<string>::iterator it = p.begin() ; it != p.end() ; ++it)
                {
                    vec.insert(board[i][j ] + *it);
                }
                // vec.insert(p.begin(),p.end());
                
                visit[i][j+1] = false;
            }
        }
        
        return vec;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> vec;
        
        m = board.size();
        if(m == 0)
            return vec;
        n = board[0].size();
        if(n == 0)
            return vec;
        
        if(words.size() == 0)
            return vec;
        
        vector<vector<bool>> visit(m,vector<bool>(n,false));
        
        Trie trie;
        for(int i = 0 ; i < words.size() ; i ++)
        {
            trie.insert(words[i]);
        }
        
        TrieNode* root = trie.root;
        set<string> s;
        
        for(int i = 0 ; i < m ; i ++)
        {
            for(int j = 0 ; j < n ; j ++)
            {
                if(root -> nodes[board[i][j] - 'a'] != NULL)
                {
                    visit[i][j] = true;
                    set<string> tmp = search(board,visit,i,j,root -> nodes[board[i][j] - 'a']);
                    s.insert(tmp.begin(),tmp.end());
                    visit[i][j] = false;
                }
            }
        }
        
        for(set<string>::iterator it = s.begin() ; it != s.end() ; ++it)
        {
            vec.push_back(*it);
        }
        
        return vec;
    }
};