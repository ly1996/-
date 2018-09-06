class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
        {
            return 0;
        }
        
        int maxLen = 1;
        
        int * minNum = new int[len];
        for(int i = 0 ; i < len ; i ++)
        {
            minNum[i] = 0;
        }
        minNum[0] = nums[0];
        
        
        for(int i = 1 ; i < len ; i ++)
        {
            int num = nums[i];
            for(int j = maxLen - 1 ; j >= 0 ; j --)
            {
                if(num > minNum[j])
                {
                    minNum[j + 1] = num;
                    if(j == maxLen - 1)
                    {
                        maxLen ++;
                    }
                    break;
                }
                else
                {
                    if(j == 0)
                    {
                        minNum[0] = num;
                    }
                }
            }
        }
        
        return maxLen;
    }
};