class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> vecReturn;
        // cout << digits.find('0') << " ; " << digits.npos<< endl;
        if(digits.find('1') != digits.npos || digits.find('0') != digits.npos)
        {
            return vecReturn;
        }
        if(digits.size() == 0)
        {
            return vecReturn;
        }
        
        string s = "";
        switch(digits[0] - '0')
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
        
        //  cout << s << " : "<< digits.size() << endl;
        if(digits.size() == 1)
        {
            for(int i = 0 ; i < s.size() ; i ++)
            {
                vecReturn.push_back(s.substr(i,1));
            }
            return vecReturn;
        }
        
        vector<string> vec = letterCombinations(digits.substr(1));
        for(int i = 0 ; i < s.size() ; i ++)
        {
            char ch = s[i];
            for(int j = 0 ; j < vec.size() ; j++)
            {
                vecReturn.push_back(s[i] + vec[j]);
            }
        }
        
        return vecReturn;
    }
};