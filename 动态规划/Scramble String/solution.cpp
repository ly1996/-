class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len = s1.length();
        int len2 = s2.length();
        if(len != len2)
        {
            return false;
        }
        if(s1 == s2)
        {
            return true;
        }
        if(len == 1)
        {
            if(s1 != s2)
            {
                return false;
            }
        }
        
        for(int i = 1 ; i < len ; i ++)
        {
            string s11 = s1.substr(0,i);
            string s12 = s1.substr(i);
            
            string s211 = s2.substr(0,i);
            string s221 = s2.substr(i);
            
            if(compare(s11, s211) && compare(s12, s221))
            {
                if(isScramble(s11,s211) && isScramble(s12,s221))
                {
                    return true;
                }
            }
        
            string s222 = s2.substr(0,len - i);
            string s212 = s2.substr(len - i);
            
            // cout << s11 << " " << s12 << " " << s21 << " " << s22 << endl;
            if(compare(s11, s212) && compare(s12, s222))
            {
                if(isScramble(s11,s212) && isScramble(s12,s222))
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool compare(string str1 , string str2){
        string s1 = str1;
        string s2 = str2;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if(s1 == s2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};