class Solution {
public:
    int longestValidParentheses(string s) {
        /*
        思想：用矩阵记录下
        坐标(i,j)：1或0代表字符串中从i到j的子字符串是否为valid parentheses
        每次迭代：只需要计算长度为偶数的子字符串
        如果s[i] != '(' 或者s[j] != ')'：直接跳过
        如果满足上述条件，则分为两种情况：
        如果(i + 1 , j - 1)为1，那么(i,j)为1
        否则则需要将子字符串拆分成两部分，分别检验两部分是否为1，如果都是，那么连接在一起构成的(i,j)也为1
        */
        
        
        int len = s.length();
        if(len == 0 || len == 1)
        {
            return 0;
        }
        
        int maxLen = 0;
        int ** canBeValidParentheses = new int *[len];
        for(int i = 0 ; i < len ; i ++)
        {
            canBeValidParentheses[i] = new int[len];
            for(int j = 0 ; j < len ; j ++)
            {
                canBeValidParentheses[i][j] = 0;
            }
        }
        
        for(int j = 0 ; j + 1 < len ; j ++)
        {
            if(s[j] == '(' && s[j + 1] == ')')
            {
                canBeValidParentheses[j][j+1] = 1;
                maxLen = 2;
            }
        }
        
        for(int i = 2 ; i <= len ; i = i + 2)
        {
            //i: 字符串长度
            bool canFind = false;
            for(int j = 0 ; j + i - 1 < len ; j ++)
            {
                //j:字符串起始位置,j+i-1:字符串终止位置
                if(s[j] == '(' && s[j + i - 1] == ')')
                {
                    if(canBeValidParentheses[j + 1][j + i - 2] == 1)
                    {
                        canBeValidParentheses[j][j + i - 1] = 1;
                        canFind = true;
                    }
                    else
                    {
                        for(int k = 2 ; k <= i - 2; k += 2)
                        {
                            //k:左边字符串的长度
                            if(canBeValidParentheses[j][j + k - 1] == 1 && canBeValidParentheses[j + k][j + i - 1] == 1)
                            {
                                canBeValidParentheses[j][j + i - 1] = 1;
                                canFind = true;
                            }
                        }
                    }
                }
            }
            if(canFind)
            {
                maxLen = i;
            }
        }
        return maxLen;
    }
};