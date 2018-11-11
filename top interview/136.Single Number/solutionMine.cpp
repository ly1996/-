class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> m;
        
        for(int num : nums)
        {
            m[num] = 0;
        }
        
        for(int num : nums)
        {
            m[num] ++;
        }
        
        for(int num : nums)
        {
            if(m[num] == 1)
            {
                return num;
            }
        }
    }
};