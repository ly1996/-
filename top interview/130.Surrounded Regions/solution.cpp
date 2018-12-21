
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0)
            return;
        int n = board[0].size();
        if(n == 0)
            return;
        
        vector<vector<int>> vecList;
        for(int i = 0 ; i < m ; i ++)
        {
            vector<int> vec(n,0);
            vecList.push_back(vec);
        }
        
        set<pair<int,int>> chars;
        set<pair<int,int>> startChars;
        
        for(int i = 0 ; i < m ; i ++)
        {
            for(int j = 0 ; j < n ; j ++)
            {
                if(board[i][j] == 'O')
                {
                    chars.insert(pair<int,int>(i,j));
                    if(i == 0 || i == m - 1 || j == 0 || j == n - 1)
                    {
                        startChars.insert(pair<int,int>(i,j));
                    }
                }
            }
        }
        
        while (!startChars.empty())
        {
            set<pair<int,int>> tmp;
            for (auto word : startChars)
            {
                // cout << word.first << " " << word.second << endl;
                chars.erase(word);
                
            }
            for (auto word : startChars)
            {
                int i = word.first;
                int j = word.second;
                vecList[i][j] = 1;
                
                if(i - 1 >= 0 && board[i - 1][j] == 'O' && chars.find(pair<int,int>(i-1,j)) != chars.end())
                {
                    tmp.insert(pair<int,int>(i-1,j));
                }
                
                if(i + 1 < m && board[i + 1][j] == 'O' && chars.find(pair<int,int>(i+1,j)) != chars.end())
                {
                    tmp.insert(pair<int,int>(i+1,j));
                }
                
                if(j - 1 >= 0 && board[i][j - 1] == 'O' && chars.find(pair<int,int>(i,j-1)) != chars.end())
                {
                    tmp.insert(pair<int,int>(i,j-1));
                }
                
                if(j + 1 < n && board[i][j + 1] == 'O' && chars.find(pair<int,int>(i,j+1)) != chars.end())
                {
                    tmp.insert(pair<int,int>(i,j+1));
                }
            }
            
            startChars = tmp;
        }
        
        for(int i = 0 ; i < m ; i ++)
        {
            for(int j = 0 ; j < n ; j ++)
            {
                if(vecList[i][j] == 0)
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};