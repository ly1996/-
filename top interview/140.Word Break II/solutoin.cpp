class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<string> vecReturn;
        
        vector<vector<int>> vecList;
        vector<int> tmp;
        vecList.push_back(tmp);
        
        vector<bool> canFind(len + 1, false);
        canFind[0] = true;
        
        for (int i = 1; i <= len ; ++ i){
            vector<int> vec;
            for (int j = 0; j < wordDict.size(); ++ j)
            {
                string word = wordDict[j];
                int wordSize =word.size();
                if (i >= wordSize && canFind[i - wordSize] && word.compare(s.substr(i - wordSize, wordSize)) == 0){
                    canFind[i] = true;
                    vec.push_back(i - wordSize);
                }
            }
            
            vecList.push_back(vec);
        }
        
        vector<int> finalFind = vecList[len];
        queue<pair<int,string>> q;
        
        for(int i = 0 ; i < finalFind.size() ; i ++)
        {
            q.push(pair<int,string>(finalFind[i],s.substr(finalFind[i])));
        }
        
        while(!q.empty())
        {
            pair<int,string> p = q.front();
            q.pop();
            
            int index = p.first;
            string str = p.second;
            
            if(index == 0)
            {
                vecReturn.push_back(p.second);
                continue;
            }
            
            vector<int> vec = vecList[index];
            
            for(int i = 0 ; i < vec.size() ; i ++)
            {
                int start = vec[i];
                
                q.push(pair<int,string>(start,s.substr(start, index - start) + " " + str));
            }
        }
        
        return vecReturn;
    }
};