class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        for(int num : nums)
        {
            if(m.find(num) == m.end())
            {
                m[num] = 1;
            }
            else
            {
                m[num] ++;
            }
        }
        
        int count = nums.size() / 2;
        map<int,int>::iterator it;
        
        for(it = m.begin() ; it != m.end() ; ++it)
        {
            if(it -> second > count)
                return it -> first;
        }
    }
};