class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vecReturn;
        map<string , vector<string>> m;
        for(int i = 0 ; i < strs.size() ; i ++)
        {
            string s = strs[i];
            sort(s.begin() ,s.end());
            map<string , vector<string>>::iterator it;
            it = m.find(s);
            if(it == m.end())
            {
                vector<string> vec;
                vec.push_back(strs[i]);
                m.insert(pair<string , vector<string>>(s , vec));
            }
            else
            {
                (it -> second).push_back(strs[i]);
            }
        }
        map<string , vector<string>>::iterator it;
        for(it = m.begin() ; it != m.end() ; it ++)
        {
            vecReturn.push_back(it->second);
        }
        return vecReturn;
    }
};