class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() == 0)
        {
            return 0;
        }
        
        stack<int> idxStack;
        
        int maxLength = 0;
        int start = -1;
        
        for(int i = 0 ; i < s.length() ; i ++)
        {
            char ch = s[i];
            if(ch == '(')
            {
                idxStack.push(i);
            }
            else
            {
                if(idxStack.empty())
                {
                    start = i;
                }
                else
                {
                    idxStack.pop();
                    if(idxStack.empty())
                    {
                        int tmpLen = i - start;
                        if(tmpLen > maxLength)
                        {
                            maxLength = tmpLen;
                        }
                    }
                    else
                    {
                        int j = idxStack.top();
                        int tmpLen = i - j;
                        if(tmpLen > maxLength)
                        {
                            maxLength = tmpLen;
                        }
                    }
                }
            }
        }
        return maxLength;
    }
};