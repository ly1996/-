class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        
        vector<int> minCounts(amount + 1 , amount + 1);
        minCounts[0] = 0;
        
        for(int i = 1 ; i <= amount ; i ++)
        {
            for(int j = 0 ; j < len ; j ++)
            {
                int coin = coins[j];
                
                if(coin > i)
                {
                    continue;
                }
                else
                {
                    int minCount = 1 + minCounts[i - coin];
                    if(minCount < minCounts[i])
                    {
                        minCounts[i] = minCount;
                    }
                }
            }
        }
        
        if(minCounts[amount] <= amount)
        {
            return minCounts[amount];
        }
        else
        {
            return -1;
        }
    }
};