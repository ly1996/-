class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int s = nums.size();
        if(s <= 1)
            return s;
        
        int len = 1 ;//返回长度也是接下来遇到的不同值的放置的位置
        int curNum = nums[0];
        for(int i = 1 ; i < s ; i ++)
        {
            if(nums[i] == curNum)continue;
            else
            {
                nums[len] = nums[i];
                len ++;
                curNum = nums[i];
            }
        }
        return len;
    }
};