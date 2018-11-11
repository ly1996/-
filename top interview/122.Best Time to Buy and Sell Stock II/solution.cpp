ˇclass Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <= 1)
        {
            return 0;
        }
        
        int maxGain = 0;
        
        int minNum = prices[0];
        int beforeNum = prices[0];
        
        for(int i = 1 ; i < len ; i ++)
        {
            int price = prices[i];
            
            if(price >= beforeNum)
            {
                beforeNum = price;
                continue;
            }
            else
            {
                int gain = beforeNum - minNum;
                maxGain += gain;
                
                minNum = price;
                beforeNum = price;
            }
        }
        
        if(prices[len - 1] != minNum)
        {
            maxGain += (prices[len - 1] - minNum);
        }
        
        return maxGain;
    }
};