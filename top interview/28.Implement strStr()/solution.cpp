class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size()) return -1;
        if(needle.size() == 0) return 0;
        
        int intReturn = -1;
        
        int cur = 0;
        int sameIdx = 0;
        
        int startIdx = -1;
        
        int m = haystack.size();
        int n = needle.size();
        
        for(;cur < m ; cur ++)
        {
            if(haystack[cur] == needle[sameIdx])
            {
                if(sameIdx == 0)
                {
                    startIdx = cur;
                }
                if(sameIdx == n - 1)
                {
                    return startIdx;
                }
                sameIdx ++;
            }
            else
            {
                if(startIdx != -1)
                {
                    cur = startIdx;
                }
                sameIdx = 0;
                startIdx = -1;
            }
        }
    
        return -1;
    }
};