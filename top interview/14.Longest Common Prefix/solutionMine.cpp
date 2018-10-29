class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        char charList[1000];
        for(int i = 0 ; i < 1000 ; i ++)
        {
            charList[i] = '\0';
        }
        int lenOfSame = 0;
        
        int len = strs.size();
        if(len == 0)
        {
            return "";
        }
        if(len == 1)
        {
            return strs[0];
        }
        
        string f = strs[0];
        for(int i = 0 ; i < f.size() ; i ++)
        {
            char ch = f[i];
            bool isSame = true;
            for(int j = 1 ; j < len ; j ++)
            {
                char tmp = strs[j][i];
                if(tmp != ch)
                {
                    isSame = false;
                    break;
                }
            }
            if(isSame)
            {
                charList[lenOfSame] = ch;
                lenOfSame ++;
            }
            else
            {
                string ss1(charList);
                return ss1;
            }
        }
        string ss1(charList);
        return ss1;
    }
};