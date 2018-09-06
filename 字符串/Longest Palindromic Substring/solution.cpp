class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "")
        {
            return "";
        }
        
        int maxLen = 1;
        int start = 0;
        int end = 0;
        
        int len = s.length();
        int ** lens = new int * [len];
        for(int i = 0 ; i < len ; i ++)
        {
            lens[i] = new int[len];
            for(int j = 0 ; j < len ; j ++)
            {
                lens[i][j] = 0;
            }
            lens[i][i] = 1;
        }
        
        for(int tmpLen = 2 ; tmpLen <= len ; tmpLen ++)
        {
            //tmpLen : 长度
            for(int i = 0 ; i + tmpLen - 1 < len ; i ++)
            {
                int j = i + tmpLen - 1;
                if(s[i] == s[j])
                {
                    int tmp_start = i + 1;
                    int tmp_end = j - 1;
                    if(tmp_start <= tmp_end)
                    {
                        if(lens[tmp_start][tmp_end] == 1)
                        {
                            lens[i][j] = 1;
                        }
                        else
                        {
                            lens[i][j] = 0;
                        }
                    }
                    else
                    {
                        lens[i][j] = 1;
                    }
                }
                else
                {
                    lens[i][j] = 0;
                }
                
                if(lens[i][j] == 1)
                {
                    maxLen = tmpLen;
                    start = i;
                    end = j;
                }
            }
        }
        
        return s.substr(start,maxLen);
    }
};