class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = triangle.size() - 2 ; i >= 0 ; i --)
        {
            vector<int> vec = triangle[i];
            vector<int> low = triangle[i + 1];
            for(int j = 0 ; j < vec.size() ; j++)
            {
                int left = low[j];
                int right = low[j + 1];
                int min = left;
                if(right < min)
                {
                    min = right;
                }
                triangle[i][j] = triangle[i][j] + min;
            }
        }
        return triangle[0][0];
    }
};