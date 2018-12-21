class Solution {
public:
    int titleToNumber(string s) {
        if(s == "")
            return 0;
        int index = 1;
        int result = 0;
        int len = s.size();
        for(int i = s.size() - 1 ; i >= 0 ; i --)
        {
            char ch = s[i];
            result += index * (ch - 'A' + 1);
            index *= 26;
        }
        
        return result;
    }
};