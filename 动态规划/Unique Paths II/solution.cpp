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
                /*
                if(obstacleGrid[i][j] == 1)
                {
                    mn[i][j] = 0;
                }
                else
                {
                    mn[i][j] = 1;
                }
                */
            }
        }
        for(int i = n - 1; i >= 0 ; i--)
        {
            if(obstacleGrid[m-1][i] == 0)
            {
                mn[m-1][i] = 1;
            }
            else
            {
                break;
            }
        }
        for(int i = m - 1; i>= 0 ; i--)
        {
            if(obstacleGrid[i][n-1] == 0)
            {
                mn[i][n-1] = 1;
            }
            else
            {
                break;
            }
        }
        /*
        for(int i = 0 ; i < m ; i ++)
        {
            for(int j = 0 ; j < n ; j ++)
            {
                cout << mn[i][j] << ' ';
            }
            cout << endl;
        }
        */
        int line = m - 2;
        int col = n - 2;
        
        while(line >= 0 && col >= 0)
        {
            for(int i = line; i >= 0 ; i --)
            {
                if(obstacleGrid[i][col] == 1)
                {
                    continue;
                }
                mn[i][col] = mn[i][col + 1] + mn[i+1][col];
            }
            for(int i = col ; i >= 0 ; i--)
            {
                if(obstacleGrid[line][i] == 1)
                {
                    continue;
                }
                mn[line][i] = mn[line][i+1] + mn[line+1][i];
            }
            line -- ;
            col --;
        }
        return mn[0][0];
    }
};