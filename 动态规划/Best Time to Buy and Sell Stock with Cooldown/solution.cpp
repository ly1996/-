class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        
        if(len <= 1)
        {
            return 0;
        }
        
        int sell = 0;
        int buy = INT_MIN;
        int prev_sell = 0;
        int prev_buy;
        
        for (int price : prices)
        {
            prev_buy = buy;
            buy = max(prev_sell - price, buy);
            prev_sell = sell;
            sell = max(prev_buy + price, sell);
        }
        
        return sell;
    }
};