class Solution {
public:
    int countSame(vector<vector<int>>& board, int i, int j, int m, int n, int same){
        if(i < 0 || i >= m || j < 0 || j >= n)
        {
            return 0;
        }
        if(same == 1)
        {
            if(board[i][j] == 1 || board[i][j] == -2)
                return 1;
            else
                return 0;
        }
        else
        {
            if(board[i][j] == 0 || board[i][j] == -1)
                return 1;
            else
                return 0;
        }
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if(m == 0)
            return;
        int n = board[0].size();
        if(n == 0)
            return;
        
        for(int i = 0 ; i < m ; i ++)
        {
            for(int j = 0 ; j < n ; j ++)
            {
                int count = 0;
                if(board[i][j] == 1)
                {
                    for(int p = -1 ; p <= 1 ; p ++)
                    {
                        for(int q = -1 ; q <= 1 ; q ++)
                        {
                            count += countSame(board, i + p, j + q, m, n, 1);
                        }
                    }
                    
                    count -= 1;
                    if(count < 2 || count > 3)
                    {
                        board[i][j] = -2;
                    }
                }
                else
                {
                    for(int p = -1 ; p <= 1 ; p ++)
                    {
                        for(int q = -1 ; q <= 1 ; q ++)
                        {
                            count += countSame(board, i + p, j + q, m, n, 1);
                        }
                    }
                    
                    if(count == 3)
                        board[i][j] = -1;
                }
                
                // cout << count << " ";
            }
            // cout << endl;
        }
        
        for(int i = 0 ; i < m ; i ++)
        {
            for(int j = 0 ; j < n ; j ++)
            {
                // cout << board[i][j] << " ";
                if(board[i][j] == -2)
                    board[i][j] = 0;
                if(board[i][j] == -1)
                    board[i][j] = 1;
            }
            // cout << endl;
        }
    }
};