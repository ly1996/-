class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> idxStack;
        vector<pair<pair<int , int> , int>> lrVec;
        
        int len = s.size();
        for(int i = 0 ; i < len ; i ++)
        {
            char ch = s[i];
            if(ch == '(')
            {
                idxStack.push(i);
            }
            else
            {
                if(idxStack.empty())
                {
                    continue;
                }
                else
                {
                    int j = idxStack.top();
                    idxStack.pop();
                    pair<int , int> a(j , i);
                    pair<pair<int,int>,int> b(a,2);
                    lrVec.push_back(b);
                    add(lrVec);
                }
            }
        }
        int maxLen = 0;
        int l = lrVec.size();
        for(int i = 0 ; i < l ; i ++)
        {
            maxLen = max(maxLen , lrVec[i].second);
        }
        return maxLen;
    }
    void add(vector<pair<pair<int , int> , int>> & lrVec){
        if(lrVec.size() == 1) return;
        while(lrVec.size() >= 2)
        {
            int len = lrVec.size();
            pair<pair<int , int> , int> lr1 = lrVec[len - 1];
            pair<pair<int , int> , int> lr2 = lrVec[len - 2];
            int minL = min(lr1.first.first , lr2.first.first);
            int maxR = max(lr1.first.second , lr2.first.second);
            if(maxR - minL + 1== lr1.second + lr2.second)
            {
                pair<int , int> a(minL , maxR);
                pair<pair<int , int> , int> b(a , lr1.second + lr2.second);
                lrVec.erase(lrVec.end());
                lrVec.erase(lrVec.end());
                lrVec.push_back(b);
            }
            else
            {
                break;
            }
        }
    }
};