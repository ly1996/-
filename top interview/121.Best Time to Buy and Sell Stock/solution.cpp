class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <= 1)
        {
            return 0;
        }
        
        int minPrice = prices[0];
        int maxGain = 0;
        
        for(int i = 1 ; i < len ; i ++)
        {
            maxGain = max(maxGain , prices[i] - minPrice);
            minPrice = min(minPrice , prices[i]);
        }
        
        return maxGain;
    }
};