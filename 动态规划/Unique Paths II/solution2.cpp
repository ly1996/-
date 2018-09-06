class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        int** mn = new int*[m];
        for(int i = 0 ; i < m ; i ++)
        {
            mn[i] = new int[n];
            for(int j = 0 ; j < n ; j ++)
            {
                mn[i][j] = 0;
            }
        }
        
        for(int i = 0 ; i < m ; i ++)
        {
            if(obstacleGrid[i][0] == 0)
            {
                mn[i][0] = 1;
            }
            else
            {
                break;
            }
        }
        
        for(int j = 0 ; j < n ; j ++)
        {
            if(obstacleGrid[0][j] == 0)
            {
                mn[0][j] = 1;
            }
            else
            {
                break;
            }
        }
        
        int line = 1;
        int col = 1;
        while(line < m && col < n)
        {
            for(int i = line ; i < m ; i ++)
            {
                if(obstacleGrid[i][col] != 1)
                {
                    mn[i][col] = mn[i][col - 1] + mn[i - 1][col];
                }
                else
                {
                    continue;
                }
            }
            
            for(int j = col ; j < n ; j ++)
            {
                if(obstacleGrid[line][j] != 1)
                {
                    mn[line][j] = mn[line - 1][j] + mn[line][j - 1];
                }
                else
                {
                    continue;
                }
            }
            
            line ++;
            col ++;
        }
        
        return mn[m-1][n-1];
    }
};