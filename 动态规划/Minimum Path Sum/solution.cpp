class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int** mn = new int*[m];
        for(int i = 0 ; i < m ; i ++)
        {
            mn[i] = new int[n];
            for(int j = 0 ; j < n ; j ++)
            {
                mn[i][j] = grid[i][j];
            }
        }
        
        for(int i = n - 2; i >= 0 ; i--)
        {
            mn[m-1][i] = mn[m-1][i] + mn[m-1][i+1];
        }
        for(int i = m - 2; i>= 0 ; i--)
        {
            mn[i][n-1] = mn[i][n-1] + mn[i+1][n-1];
        }
        //cout << "初始化完毕"<<endl;
        
        int line = m - 2;
        int col = n - 2;
        
        while(line >= 0 && col >= 0)
        {
            for(int i = line; i >= 0 ; i --)
            {
                int minStep = mn[i][col + 1];
                if(mn[i+1][col] < minStep)
                {
                    minStep = mn[i+1][col];
                }
                mn[i][col] = mn[i][col] + minStep;
            }
            for(int i = col - 1; i >= 0 ; i--)
            {
                int minStep = mn[line][i+1];
                if(mn[line+1][i] < minStep)
                {
                    minStep = mn[line+1][i];
                }
                mn[line][i] = mn[line][i] + minStep;
            }
            line -- ;
            col --;
        }
        
        return mn[0][0];
    }
};