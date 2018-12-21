class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {        
        bool * dp = new bool[s.length() + 1];
        dp[0] = true;
        for (int i = 1; i < s.length() + 1; ++ i){
            dp[i] = false;
            for (int j = 0; j < wordDict.size(); ++ j){
                int wordSize = wordDict[j].size();
                if (i >= wordSize && dp[i - wordSize] && wordDict[j].compare(s.substr(i - wordSize, wordSize)) == 0){
                    dp[i] = true;
                }
            }
        }
        return dp[s.length()];
    }
};