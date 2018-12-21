class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        
        int start = 0;
        int end = len - 1;
        
        int i = 0;
        while(i <= end)
        {
            if(nums[i] == 0 && i != start)
            {
                swap(nums[start],nums[i]);
                start ++;
            }
            else if(nums[i] == 2 && i != end)
            {
                swap(nums[end],nums[i]);
                end --;
            }
            else
            {
                i ++;
            }
        }
    }
};