class Solution {
public:
    static bool compare(string a , string b){
        if(a.length() < b.length())
        {
            return true;
        }
        else if(a.length() == b.length())
        {
            return a < b;
        }
        else
        {
            return false;
        }
    }
    
    bool isSub(string a , string b){
        int i = 0;
        int j = 0;
        while(i < a.length() && j < b.length())
        {
            if(a[i] == b[j])
            {
                i ++;
            }
            j ++;
        }
        if(i == a.length())
        {
            return true;
        }
        return false;
    }
    
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(),strs.end(),compare);
        
        for(int i = 0 ; i < strs.size(); i ++)
        {
            string str = strs[i];
            cout << str << " ";
        }
        
        int longest = -1;
        
        int len = strs.size();
        
        for(int i = len - 1 ; i >= 0 ; i --)
        {
            string str = strs[i];
            // cout << str << " ";
            if(i - 1 >= 0 && str == strs[i - 1])
            {
                while(i - 1 >= 0 &&str == strs[i - 1])
                {
                    i --;
                }
                continue;
            }
            
            bool isPart = false;
            for(int j = i + 1 ; j < strs.size(); j++)
            {
                if(isSub(str,strs[j]))
                {
                    isPart = true;
                    break;
                }
            }
            
            if(isPart)
            {
                continue;
            }
            else
            {
                return str.length();
            }
        }
        return longest;
    }
};