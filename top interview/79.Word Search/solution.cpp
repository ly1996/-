class Solution {
public:
    bool existStartij(vector<vector<char>>& board, string& word, int index, int i , int j){
        // cout << i << " " << j << " " << index << endl;
        if(index == word.size())
            return true;
        char tmpChar = board[i][j];
        board[i][j] = '\0';
        
        if(i - 1 >= 0)
        {
            if(board[i-1][j] == word[index])
            {
                bool tmp = existStartij(board, word, index + 1, i - 1 , j);
                if(tmp)
                {
                    return true;
                }
            }
        }
        
        if(j + 1 < board[0].size())
        {
            if(board[i][j+1] == word[index])
            {
                bool tmp = existStartij(board, word, index + 1, i , j + 1);
                if(tmp)
                    return true;
            }
        }
        
        if(j - 1 >= 0)
        {
            if(board[i][j-1] == word[index])
            {
                bool tmp = existStartij(board, word, index + 1, i , j - 1);
                if(tmp)
                    return true;
            }
        }
        
        if(i + 1 < board.size())
        {
            if(board[i+1][j] == word[index])
            {
                bool tmp = existStartij(board, word, index + 1, i + 1 , j);
                if(tmp)
                    return true;
            }
        }
        
        board[i][j] = tmpChar;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0 ; i < m ; i ++)
        {
            for(int j = 0 ; j < n ; j ++)
            {
                if(board[i][j] == word[0])
                {
                    bool tmp = existStartij(board , word, 1 , i , j);
                    if (tmp)
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};