class Solution {
public:
    int numSquares(int n) {
        int * nums = new int[n + 1];
        for(int i = 0 ; i <= n ; i ++)
        {
            nums[i] = -1;
        }
        
        vector<int> squares;
        int i = 1;
        while(true)
        {
            int square = i * i;
            if(square <= n)
            {
                nums[square] = 1;
                squares.push_back(square);
                i ++;
            }
            else
            {
                break;
            }
        }
        
        int lenOfSquares = squares.size();
        
        for(i = 1 ; i <= n ; i ++)
        {
            if(nums[i] == 1)
            {
                continue;
            }
            else
            {
                int minNum = i;
                for(int j = 0 ; j < lenOfSquares ; j ++)
                {
                    int square = squares[j];
                    if(square > i)
                    {
                        break;
                    }
                    int newNum = 1 + nums[i - square];
                    if(newNum < minNum)
                    {
                        minNum = newNum;
                    }
                }
                nums[i] = minNum;
            }
        }
        
        return nums[n];
    }
};