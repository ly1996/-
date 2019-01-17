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
        
        return search(matrix,target,0,m-1,0,n-1);
    }
    
    bool search(vector<vector<int>>& matrix, int target, int begin_i, int end_i, int begin_j, int end_j){
        if(begin_i > end_i || begin_j > end_j)
            return false;
        if(begin_i == end_i && begin_j == end_j)
            return matrix[begin_i][begin_j] == target;
        int mid_i = (begin_i + end_i)/2;
        int mid_j = (begin_j + end_j)/2;
        
        // cout << matrix[mid_i][mid_j] << endl;
        
        if(matrix[mid_i][mid_j] == target)
            return true;
        else if(matrix[mid_i][mid_j] > target)
        {
            if(search(matrix,target,begin_i,mid_i,begin_j,mid_j))
                return true;
            if(search(matrix,target,begin_i,mid_i,mid_j+1,end_j))
                return true;
            if(search(matrix,target,mid_i+1,end_i,begin_j,mid_j))
                return true;
            return false;
        }
        else
        {
            if(search(matrix,target,mid_i+1,end_i,mid_j+1,end_j))
                return true;
            if(search(matrix,target,begin_i,mid_i,mid_j+1,end_j))
                return true;
            if(search(matrix,target,mid_i+1,end_i,begin_j,mid_j))
                return true;
            return false;
        }
    }
};