class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vecReturn;
        
        sort(nums.begin() , nums.end());
        int len = nums.size();
        int right = len - 1;
        for(int i = 0 ; i <= len - 3 ; i ++)
        {
            int num = nums[i];
            if(i - 1 >= 0 && num == nums[i -1])
            {
                continue;
            }
            int l = i + 1;
            int r = right;
            while(l < r)
            {
                if(l > i + 1 && nums[l] == nums[l - 1])
                {
                    l ++;
                    continue;
                }
                if(r < right && nums[r] == nums[r + 1])
                {
                    r --;
                    continue;
                }
                int sum = num + nums[l] + nums[r];
                if(sum > 0)
                {
                    r --;
                }
                else if(sum == 0)
                {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);  
                    tmp.push_back(nums[l]);  
                    tmp.push_back(nums[r]);  
                    vecReturn.push_back(tmp);
                    l ++;
                    r --;
                }
                else
                {
                    l ++;
                }
            }
        }
        
        return vecReturn;
    }
};