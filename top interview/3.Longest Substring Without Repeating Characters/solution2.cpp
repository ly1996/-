class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
        {
            return 0;
        }
	//利用map实现
        int start = -1;
        int maxLen = 1;
        map<char,int> m;
        m[s[0]] = 0;
        for(int i = 1 ; i < s.size() ; i ++)
        {
            char ch = s[i];
            if(m.find(ch) != m.end())
            {
                int index = m[ch];
                if(index > start)
                {
                    start = index;
                }
            }
            m[ch] = i;
            if(i - start > maxLen)
            {
                maxLen = i - start;
            }
        }
        
        return maxLen;
    }
};