class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        
        int before2 = 0;
        int before1 = nums[0];
        int maxCount = nums[0];
        
        for(int i = 1; i < len ; i ++)
        {
            int tmp = nums[i] + before2;
            if(nums[i] + before2 > before1)
            {
                before2 = before1;
                before1 = tmp;
            }
            else
            {
                before2 = before1;
            }
        }
        
        return before1;
    }
};