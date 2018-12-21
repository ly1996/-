class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
            return false;
        
        bool * visited = new bool[rows * cols];
        memset(visited,false,rows*cols);
        
        int pathLength = 0;
        for(int i = 0 ; i < rows ; i ++)
        {
            for(int j = 0 ; j < cols ; j ++)
            {
                if(hasPathCore(matrix, rows, cols, i, j, str, pathLength, visited))
                {
                    return true;
                }
            }
        }
        
        delete []visited;
        return false;
    }
    
    bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int &pathLength, bool *visited){
        if(str[pathLength] == '\0')
            return true;
        
        if(row >= 0 && row < rows && col >= 0 && col < cols && matrix[row * cols + col] == str[pathLength] && !visited[row * cols + col])
        {
            ++pathLength;
            visited[row * cols + col] = true;
            
            bool hasPath = hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited) || hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)
                || hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited) || hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited);
            
            if(hasPath)
                return true;
            --pathLength;
            visited[row * cols + col] = false;
        }
        
        return false;
    }
};