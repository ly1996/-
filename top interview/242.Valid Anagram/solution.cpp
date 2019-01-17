class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26,0);
        int len_s = s.size();
        int len_t = t.size();
        if(len_s != len_t)
            return false;
        
        for(int i = 0 ; i < len_s ; i ++)
        {
            count[s[i] - 'a'] ++;
        }
        
        for(int i = 0 ; i < len_t ; i ++)
        {
            if(count[t[i] - 'a'] == 0)
                return false;
            else
            {
                count[t[i] - 'a'] --;
            }
        }
        
        return true;
    }
};