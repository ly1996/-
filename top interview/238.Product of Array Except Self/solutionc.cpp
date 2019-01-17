class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        
        vector<int> vec(len,1);
        
        vec[1] = nums[0];
        for(int i = 2; i < len ; i ++)
        {
            vec[i] = nums[i-1] * vec[i-1];
        }
        
        int before = nums[len-1];
        for(int i = len - 2; i >= 0 ; i --)
        {
            vec[i] = vec[i] * before;
            before = nums[i] * before;
        }
        
        return vec;
    }
};s