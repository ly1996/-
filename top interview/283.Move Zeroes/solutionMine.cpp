class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0; // 0的位置
        int j = 0;
        int len = nums.size();
        while(i < len && j < len)
        {
            while(i < len && nums[i] != 0)
                i ++;
            j = i + 1;
            while(j < len && nums[j] == 0)
                j ++;
            if(i < len && j < len)
                swap(nums[i],nums[j]);
            i ++;
        }
    }
};