class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        
        int i = 0;
        for(int i = 0 ; i < len ; i ++)
        {
            if(nums[i] == i + 1)
                continue;
            else if(nums[i] == -1)
                continue;
            int start = i;
            int j = nums[i] - 1;
            while(j != start)
            {
                if(nums[j] == -1)
                    return j + 1;
                else
                {
                    int tmp = nums[j] - 1;
                    nums[j] = -1;
                    j = tmp;
                }
            }
            
            nums[start] = -1;
        }
        
        return 0;
    }
};