class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        int m = matrix.size();
        if(m == 0)
        {
            m_sum = 0;
            n_sum = 0;
            return;
        }
        int n = matrix[0].size();
        m_sum = m;
        n_sum = n;
        
        for(int i = 0 ; i < m + 1; i ++)
        {
            vector<int> tmp;
            for(int j = 0 ; j < n + 1; j ++)
            {
                tmp.push_back(0);
            }
            matrix_sum.push_back(tmp);
        }
        
        for(int i = 0 ; i <= m ; i ++){
            matrix_sum[i][0] = 0;
        }
        
        for(int j = 0 ; j <= n ; j ++)
        {
            matrix_sum[0][j] = 0;
        }
        
        for(int i = 1 ; i <= m ; i ++)
        {
            for(int j = 1 ; j <= n ; j ++)
            {
                matrix_sum[i][j] = matrix[i - 1][j - 1] + matrix_sum[i - 1][j] + matrix_sum[i][j - 1] - matrix_sum[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        return matrix_sum[row2 + 1][col2 + 1] - matrix_sum[row1][col2 + 1] - matrix_sum[row2 + 1][col1] + matrix_sum[row1][col1];
    }
private:
    vector<vector<int>> matrix_sum;
    int m_sum;
    int n_sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */