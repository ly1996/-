class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int maxNum = nums[0];
        
        int maxN = -1,minN = 1;
        
        if(nums[0] > 0)
        {
            maxN = nums[0];
        }
        else
        {
            minN = nums[0];
        }
        
        for(int i = 1 ; i < len ; i ++)
        {
            int num = nums[i];
            
            if(num >= 0)
            {
                maxN = max(num * maxN , num);
                minN = num * minN;
            }
            else
            {
                int beforeMaxx = maxN;
                maxN = num * minN;
                minN = min(num * beforeMaxx , num);
            }
            
            if(maxN > maxNum)
            {
                maxNum = maxN;
            }
        }

        return maxNum;
    }
};