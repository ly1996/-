class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
        {
            return "1";
        }
        
        vector<int> vecReturn = {1};
        
        for(int i = 2 ; i <= n ; i ++)
        {
            vector<int> tmp;
            int num = vecReturn[0];
            int count = 1;
            for(int j = 1 ; j < vecReturn.size() ; j ++)
            {
                if(vecReturn[j] == num)
                {
                    count ++;
                    continue;
                }
                
                tmp.push_back(count);
                tmp.push_back(num);
                
                num = vecReturn[j];
                count = 1;
            }
            tmp.push_back(count);
            tmp.push_back(num);
            
            vecReturn = tmp;
        }
        
        string s = "";
        stringstream ss;
        for(int i = 0 ; i < vecReturn.size() ; i ++)
            ss << vecReturn[i];
        ss >> s;
        return s;
    }
};