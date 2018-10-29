class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
        {
            return "";
        }
        
        for(int i = 0 ; i < strs[0].size() ; i ++)
        {
            char ch = strs[0][I];//基准字符
            for(int j = 0 ; j < strs.size() ; j ++)
            {
                if(strs[j].size() == i || strs[j][i] != ch)//不够长或者不一致
                {
                    return strs[0].substr(0,i);
                }
            }
        }
        
        return strs[0];
    }
};