class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vecList;
        map<string,vector<string>> m;
        
        for(int i = 0 ; i < strs.size() ; i ++)
        {
            string str = strs[i];
            
            vector<int> count(26,0);
            
            for(char ch : str)
            {
                count[ch - 'a'] = count[ch - 'a'] + 1;
            }
            
            string result = "";
            
            for(int j = 0 ; j < 26 ; j ++)
            {
                result += (char)(count[j] + '0');
            }
            
            // cout << result << endl;
            
            if(m.find(result) == m.end())
            {
                vector<string> vec;
                vec.push_back(str);
                m.insert(pair<string,vector<string>>(result,vec));
            }
            else
            {
                m[result].push_back(str);
            }
        }
        
        map<string,vector<string>>::iterator itr = m.begin();
        for(; itr != m.end() ; itr ++)
        {
            vecList.push_back(itr -> second);
        }
        
        return vecList;
    }
};