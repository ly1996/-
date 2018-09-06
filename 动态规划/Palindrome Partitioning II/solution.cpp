class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        int ** min = new int *[len];
        for(int i = 0 ; i < len ; i ++)
        {
            min[i] = new int[len];
            min[i][i] = 0;
        }
        
        for(int gap = 2; gap <= len ; gap ++)
        {
            //gap:子字符串的长度
            for(int i = 0 ; i < len ; i ++)
            {
                //i:字符串的起始位置,j:字符串结束位置
                int j = i + gap - 1;
                if(j >= len)
                {
                    break;
                }
                string tmpStr = s.substr(i,gap);
                if(isPalindrome(tmpStr))
                {
                    min[i][j] = 0;
                    continue;
                }
                int minLen = len;
                for(int k = i ; k < j ; k ++)
                {
                    if(min[i][k] + min[k + 1][j] < minLen)
                    {
                        minLen = min[i][k] + min[k + 1][j];
                    }
                }
                min[i][j] = minLen + 1;
                
                // cout << tmpStr << " "<< i << " " << j << " : " << minLen << endl;
            }
        }
        
        return min[0][len - 1];
    }
    
    bool isPalindrome(string s){
            int len = s.length();
            int mid = len / 2;
            for(int i = 0 ; i < len ; i ++)
            {
                if(s[i] != s[len - 1 - i])
                {
                    return false;
                }
            }
            return true;
        }
};