class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> lines;
        vector<int> beforeLine(n,1);
        
        for(int i = 1 ; i < m ; i ++)
        {
            vector<int> line(n,1);
            for(int j = 1 ; j < n ; j ++)
            {
                line[j] = beforeLine[j] + line[j - 1];
            }
            
            beforeLine = line;
        }
        
        return beforeLine[n - 1];
    }
};