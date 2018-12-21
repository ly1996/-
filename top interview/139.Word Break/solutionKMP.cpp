class Solution {
public:
    vector<int> computePrefixFunction(string p)
    {
        int m = p.size();
        vector<int> vec(m + 1,0);
        p = " " + p;
        
        int k = 0;
        for(int q = 2; q <= m ; q ++)
        {
            while(k > 0 && p[k + 1] != p[q])
            {
                k = vec[q];
            }
            if(p[k + 1] == p[q])
            {
                k = k + 1;
            }
            vec[q] = k;
        }
        
        return vec;
    }
    
    vector<pair<int,int>> kmpMatcher(string t, string p)
    {
        int n = t.size();
        int m = p.size();
        
        vector<int> vec = computePrefixFunction(p);
        
        vector<pair<int,int>> list;
        
        int q = 0;
        
        for(int i = 0 ; i < n ; i ++)
        {
            while(q > 0 && p[q] != t[i])
            {
                q = vec[q];
            }
            
            if(p[q] == t[i])
            {
                q = q + 1;
            }
            
            if(q == m)
            {
                list.push_back(pair<int,int>(i-m+1,i));
                q = vec[q];
            }
        }
        
        cout << list.size() <<  endl;
        
        return list;
    }
    
    static bool compare(pair<int,int> a , pair<int,int> b){
        if(a.first == b.first)
        {
            return a.second < b.second; 
        }
        return a.first < b.first;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<pair<int,int>> words;
        
        int len = wordDict.size();
        for(int i = 0 ; i < len ; i ++)
        {
            string word = wordDict[i];
            vector<pair<int,int>> list = kmpMatcher(s,word);
            words.insert(words.end(),list.begin(),list.end());
        }
        
        sort(words.begin(),words.end(),compare);
        
        vector<int> canFind(s.size(),0);
        
        for(int i = 0 ; i < words.size() ; i ++)
        {
            pair<int,int> word = words[i];
            if(word.first == 0)
            {
                canFind[word.second] = 1;
            }
            else
            {
                if(canFind[word.first - 1] == 1)
                {
                    canFind[word.second] = 1;
                }
            }
        }
        
        return canFind[s.size() - 1] == 1;
    }
};