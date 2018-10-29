class Solution {
public:
    int maxSubArray(vector<int>& nums) {      
        int size = nums.size();
        if(size == 1)
        {
            return nums[0];
        }
        
        int sum = nums[0];
        int maxSum = sum;
        for(int i = 1 ; i < size ; i ++)
        {
            sum = max(0,sum);
            
            sum += nums[i];
            
            maxSum = max(sum,maxSum);
        }
        
        return maxSum;
    }
};