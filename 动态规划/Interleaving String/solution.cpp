class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if(len1 + len2 != len3)
        {
            return false;
        }
        
        string s4 = s1 + s2;
        string s5 = s3;
        sort(s4.begin(),s4.end());
        sort(s5.begin(),s5.end());
        
        if(s4 == s5)
        {
            
        }
        else
        {
            return false;
        }
        
        int ** canForm = new int *[len1 + 1];
        for(int i = 0 ; i <= len1 ; i ++)
        {
            canForm[i] = new int[len2 + 1];
            for(int j = 0 ; j <= len2 ; j ++)
            {
                canForm[i][j] = 0;
            }
        }
        
        canForm[0][0] = 1;
        for(int i = 1 ; i <= len1 ; i ++)
        {
            if(s1[i - 1] == s3[i - 1])
            {
                canForm[i][0] = 1; 
            }
            else
            {
                break;
            }
        }
        for(int j  = 1 ; j <= len2 ; j ++)
        {
            if(s2[j - 1] == s3[j - 1])
            {
                canForm[0][j] = 1;
            }
            else
            {
                break;
            }
        }
        
        for(int i = 1 ; i <= len1 ; i ++)
        {
            for(int j = 1 ; j <= len2 ; j ++)
            {
                //代表s3前i+j字符构成的字符串能否被s1前i个字符构成的字符串和s2前j个字符构成的字符串构成
                char ch1 = s1[i - 1];
                char ch2 = s2[j - 1];
                char ch3 = s3[i + j - 1];
                if(ch1 == ch2)
                {
                    if(ch3 != ch1)
                    {
                        canForm[i][j] = 0;
                    }
                    else
                    {
                        if(canForm[i][j - 1] == 1 || canForm[i - 1][j] == 1)
                        {
                            canForm[i][j] = 1;
                        }
                        else
                        {
                            canForm[i][j] = 0;
                        }
                    }
                }
                else
                {
                    if(ch1 == ch3)
                    {
                        canForm[i][j] = canForm[i - 1][j];
                    }
                    else if(ch2 == ch3)
                    {
                        canForm[i][j] = canForm[i][j - 1];
                    }
                    else
                    {
                        canForm[i][j] = 0;
                    }
                }
            }
        }
        
        // for(int i = 0 ; i <= len1 ; i ++)
        // {
        //     for(int j = 0 ; j <= len2 ; j ++)
        //     {
        //         cout << canForm[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        if(canForm[len1][len2] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};