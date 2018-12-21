class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m == 0)
            return 0;
        int n = grid[0].size();
        if(n == 0)
            return 0;
        
        // vector<vector<bool>> visit;
        // for(int i = 0 ; i < m ; i ++)
        // {
        //     vector<bool> vec(n,false);
        //     visit.push_back(vec);
        // }
        
        // cout << m << " " << n << endl;
        
        int count = 0;
        for(int i = 0 ; i < m ; i ++)
        {
            for(int j = 0 ; j < n ; j ++)
            {
                if(grid[i][j] == '1')
                {
                    count ++;
                    search(grid,i,j,m,n);
                }
            }
        }
        
        return count;
    }
    
    void search(vector<vector<char>>& grid,int i,int j,int m,int n){
        if(i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == '1')
        {
            grid[i][j] = '0';
            search(grid,i-1,j,m,n);
            search(grid,i+1,j,m,n);
            search(grid,i,j-1,m,n);
            search(grid,i,j+1,m,n);
        }
        else
            return;
    }
};