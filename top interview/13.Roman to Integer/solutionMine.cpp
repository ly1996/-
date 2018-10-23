class Solution {
public:
    int romanToInt(string s) {
        int len = s.size();
        int value = 0;
        map<char,int> m;
        m['M'] = 1000;
        m['C'] = 100;
        m['D'] = 500;
        m['X'] = 10;
        m['L'] = 50;
        m['I'] = 1;
        m['V'] = 5;
        
        int i = 0;
        while(i < len)
        {
            char ch = s[i];
            int per = m[ch];
            int count = per;
            while(i + 1 < len && s[i + 1] == ch)
            {
                count += per;
                i += 1;
            }
            
            if(i + 1 < len && m[s[i + 1]] > per)
            {
                count = m[s[i + 1]] - count;
                i += 1;
            }
            
            value += count;
            i += 1;
        }
        
        return value;
    }
};