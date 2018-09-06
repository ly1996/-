class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len < 2)
        {
            return 0;
        }
        
        int min = prices[0];
        int gain = 0;
        int maxGain = 0;
        for(int i = 1 ; i < len; i ++){
            int price = prices[i];
            int tmpGain = price - min;
            if(tmpGain > gain){
                gain = tmpGain;
            }
            
            if(price < min){
                min = price;
            }
            
            //起始买的位置
            int min2 = prices[i];
            int gain2 = 0;
            for(int j = i + 1 ; j < len ; j ++)
            {
                int price2 = prices[j];
                int tmpGain2 = price2 - min2;
                if(tmpGain2 > gain2){
                    gain2 = tmpGain2;
                }
                if(price2 < min2){
                    min2 = price2;
                }
            }
            if(gain + gain2 > maxGain)
            {
                maxGain = gain + gain2;
            }
        }
        
        return maxGain;
    }
};