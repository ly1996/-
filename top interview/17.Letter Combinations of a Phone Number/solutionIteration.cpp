class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> vecReturn;
        
        int len = digits.size();
        if(len == 0)
        {
            return vecReturn;
        }
        
        vecReturn.push_back("");
        
        for(int i = 0 ; i < len ; i ++)
        {
            vector<string> tmp;
            char ch = digits[i];
            string s = "";
            switch(digits[i] - '0')
            {
                case 2:s = "abc";break;
                case 3:s = "def";break;
                case 4:s = "ghi";break;
                case 5:s = "jkl";break;
                case 6:s = "mno";break;
                case 7:s = "pqrs";break;
                case 8:s = "tuv";break;
                case 9:s = "wxyz";break;
            }
            
            for(int j = 0 ; j < s.size() ; j ++)
            {
                for(int k = 0 ; k < vecReturn.size() ; k ++)
                {
                    tmp.push_back(vecReturn[k] + s[j]);
                }
            }
            
            vecReturn = tmp;
        }
        
        return vecReturn;
    }
};