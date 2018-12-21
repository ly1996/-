class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return;
        
        int n = matrix[0].size();
        if(n == 0)
            return;
        
        set<int> lines;
        set<int> cols;
        
        for(int i = 0 ; i < m ; i ++)
        {
            for(int j = 0 ; j < n ; j ++)
            {
                if(matrix[i][j] == 0)
                {
                    lines.insert(i);
                    cols.insert(j);
                }
            }
        }
        
        set<int>::iterator it;
        
        for(it = lines.begin() ; it != lines.end() ; ++it)
        {
            int i = *it;
            for(int j = 0 ; j < n ; j ++)
            {
                matrix[i][j] = 0;
            }
        }
        
        for(it = cols.begin() ; it != cols.end() ; ++it)
        {
            int j = *it;
            for(int i = 0 ; i < m ; i ++)
            {
                matrix[i][j] = 0;
            }
        }
    }
};