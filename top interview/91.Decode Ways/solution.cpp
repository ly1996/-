class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        if(s[0] == '0')
        {
            return 0;
        }
        
        vector<int> count(len + 1,0);
        count[0] = 1;
        count[1] = 1;
        
        for(int i = 2 ; i <= len ; i ++)
        {
            if(s[i - 1] == '0')
            {
                if(s[i - 2] > '0' && s[i - 2] <= '2')
                {
                    count[i] = count[i - 2];
                    continue;
                }
                else
                {
                    return 0;
                }
            }
            if(s[i - 2] == '0')
            {
                count[i] = count[i - 1];
                continue;
            }
            int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if(num <= 26)
            {
                count[i] = count[i - 1] + count[i - 2];
            }
            else
            {
                count[i] = count[i - 1];
            }
        }
        
        return count[len];
    }
};