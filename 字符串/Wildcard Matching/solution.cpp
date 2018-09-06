class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.length();
        int len2 = p.length();
        
        bool equal[len1 + 1][len2 + 1];
        equal[0][0] = true;
        
        for(int i = 1 ; i <= len1 ; i ++)
        {
            equal[i][0] = false;
        }
        
        for(int i = 1 ; i <= len2 ; i ++)
        {
            if(p[i - 1] == '*' && equal[0][i - 1] == true)
            {
                equal[0][i] = true;
            }
            else
            {
                 equal[0][i] = false;
            }
        }
        
        for(int i = 1 ; i <= len1 ; i ++)
        {
            for(int j = 1 ; j <= len2 ; j ++)
            {
                char ch1 = s[i - 1];
                char ch2 = p[j - 1];
                
                if(ch2 != '*' && ch2 != '?')
                {
                    if(ch1 == ch2)
                    {
                        equal[i][j] = equal[i - 1][j - 1];
                    }
                    else
                    {
                        equal[i][j] = false;
                    }
                }
                else if(ch2 == '?')
                {
                    equal[i][j] = equal[i - 1][j - 1];
                }
                else
                {
                    equal[i][j] = false;
                    for(int k = i ; k >= 0 ; k --)
                    {
                        if(equal[k][j - 1] == true)
                        {
                            equal[i][j] = true;
                            break;
                        }
                    }
                } 
            }
        }
        
        return equal[len1][len2];
    }
};