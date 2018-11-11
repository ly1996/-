class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1)
        {
            return true;
        }
        
        int m = 0;
        int i = 0;
        for(; i <= len - 1; i ++)
        {
            if(i > m)
                return false;
            m = max(m , i + nums[i]);
        }
        
        return true;
    }
};