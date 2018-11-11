class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxCount = 0;
        set<int> s(nums.begin(), nums.end());
        
        set<int>::iterator it = s.begin();
        
        for(; it != s.end() ; ++ it)
        {
            int num = *it;
            int count = 1;
            if(s.find(num - 1) == s.end())
            {
                int y = num + 1;
                while(s.find(y) != s.end())
                {
                    count ++;
                    y += 1;
                }
            }
            
            maxCount = max(count ,maxCount);
        }
        
        return maxCount;
    }
};