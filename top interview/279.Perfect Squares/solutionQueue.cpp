class Solution 
{   
public:
    int numSquares(int n) 
    {  
        if(n <= 0)
            return 0;
        vector<int> counts(n+1,-1);
        vector<int> squares;
        queue<int> q;
        
        int i;
        for(i = 1; i * i <= n; i ++)
        {
            counts[i * i] = 1;
            squares.push_back(i * i);
            q.push(i * i);
        }
        if(counts[n] == 1)
            return 1;
        
        int count = 1;
        while(!q.empty())
        {
            count ++;
            int size = q.size();
            
            for(i = 0 ; i < size ; i ++)
            {
                int x = q.front();
                
                for(int j = 0 ; j < squares.size() ; j ++)
                {
                    if(x + squares[j] == n)
                        return count;
                    else if(x + squares[j] < n)
                    {
                        if(counts[x + squares[j]] == -1)
                        {
                            counts[x + squares[j]] = count;
                            q.push(x + squares[j]);
                        }
                    }
                    else
                        break;
                }
                
                q.pop();
            }
        }
        
        return 0;
    }  
}; 