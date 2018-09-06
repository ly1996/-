class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        if(len == 1)
        {
            return false;
        }
        string s2 = s + s;
        
        s2 = s2.substr(1,len * 2 - 2);
        if(s2.find(s) != -1)
        {
            return true;
        }
        return false;
    }
};