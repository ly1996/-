class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(rows == 0 || cols == 0 || threshold < 0)
            return 0;
        bool * visited = new bool[rows * cols];
        memset(visited,false,rows * cols);
        
        return movingCountCore(threshold, rows, cols, 0, 0, visited);
    }
    
    int movingCountCore(int threshold, int rows, int cols, int row, int col, bool * visited){
        int count = 0;
        if(isValid(row,col,rows,cols,visited,threshold))
        {
            visited[row * cols + col] = true;
            count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited) + movingCountCore(threshold, rows, cols, row + 1, col, visited)
                + movingCountCore(threshold, rows, cols, row, col - 1, visited) + movingCountCore(threshold, rows, cols, row, col + 1, visited);
            return count;
        }
        else
        {
            return 0;
        }
    }
    
    bool isValid(int i, int j, int rows, int cols, bool * visited, int threshold){
        if(i >= 0 && i < rows && j >= 0 && j < cols && visited[i * cols + j] == false && getSum(i) + getSum(j) <= threshold)
            return true;
        return false;
    }
    
    int getSum(int i){
        int sum = 0;
        while(i > 0)
        {
            sum += i % 10;
            i /= 10;
        }
        
        return sum;
    }
};