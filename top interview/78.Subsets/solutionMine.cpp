class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        
        vector<vector<int>> result;
        
        vector<int> count(len,0);
        
        for(int i = 0 ; i < pow(2,len); i++)
        {
            vector<int> vec;
            for(int j = 0 ; j < len ; j ++)
            {
                if(count[j] == 1)
                {
                    vec.push_back(nums[j]);
                }
            }
            result.push_back(vec);
            
            int add = 1;
            for(int j = 0 ; j < len ; j ++)
            {
                int tmp = (count[j] + add) % 2;
                add = (count[j] + add) / 2;
                count[j] = tmp;
            }
        }
        
        return result;
    }
};