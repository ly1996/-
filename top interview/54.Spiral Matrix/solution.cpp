class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> vec;
        
        int m = matrix.size();
        if(m == 0)
        {
            return vec;
        }
        int n = matrix[0].size();
        if(n == 0)
        {
            return vec;
        }
        
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = m - 1;
        
        while(vec.size() < m * n)
        {
            for(int j = left ; j <= right ; j ++)
            {
                // cout << matrix[top][j] << " ";
                vec.push_back(matrix[top][j]);
            }
            top ++;
            
            if(vec.size() == m * n)
            {
                break;
            }
            
            for(int i = top ; i <= bottom ; i ++)
            {
                // cout << matrix[i][right] << " ";
                vec.push_back(matrix[i][right]);
            }
            right --;
            
            if(vec.size() == m * n)
            {
                break;
            }
            
            for(int j = right ; j >= left ; j --)
            {
                // cout << matrix[bottom][j] << " ";
                vec.push_back(matrix[bottom][j]);
            }
            bottom --;
            
            if(vec.size() == m * n)
            {
                break;
            }
            
            for(int i = bottom ; i >= top ; i --)
            {
                // cout << matrix[i][left] << " ";
                vec.push_back(matrix[i][left]);
            }
            left ++;
            
            if(vec.size() == m * n)
            {
                break;
            }
        }
        
        return vec;
    }
};