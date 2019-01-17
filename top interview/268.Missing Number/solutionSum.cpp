class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        
        int sum = 0;
        for(int i = 0 ; i < len ; i ++)
            sum += nums[i];
        
        int real = (1 + len) * len / 2;
        
        return real - sum;
    }
};