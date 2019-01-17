class Solution {
public:
    int m;
    int n;
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m = matrix.size();
        if(m == 0)
            return false;
        n = matrix[0].size();
        if(n == 0)
            return false;
        
        int i = 0;
        int j = n - 1;
        while(i < m && j >= 0)
        {
            // cout << i << " " << j << endl;
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target)
            {
                j --;
            }
            else
            {
                i ++;
            }
        }
        
        return false;
    }
};