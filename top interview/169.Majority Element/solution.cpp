class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int candidate = nums[0];
        int len = nums.size();
        for(int i = 1 ; i < len ; i ++)
        {
            int num = nums[i];
            if(count == 0)
                candidate = num;
            if(num == candidate)
                count += 1;
            else
                count -= 1;
        }
        
        return candidate;
    }
};