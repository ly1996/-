class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        nums.push_back(-1);
        for(int i = 0 ; i < len + 1; i ++)
        {
            while(nums[i] != -1 && nums[i] != i)
            {
                // cout << nums[i] << " " << nums[nums[i]] << endl;
                swap(nums[i],nums[nums[i]]);
            }
        }
        
        for(int i = 0 ; i < len + 1 ; i ++)
        {
            if(nums[i] == -1)
                return i;
        }
    }
};