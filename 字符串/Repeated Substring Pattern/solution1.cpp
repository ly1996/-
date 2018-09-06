class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        
        if(len == 1)
        {
            return false;
        }
        
        // bool canForm[len - 1];
        set<int> form;
        for(int i = 1 ; i <= len - 1 ; i ++)
        {
            if(len % i == 0)
            {
                form.insert(i);
            }
        }
        
        set<int>::iterator it;

        for(int i = 1 ; i < len ; i ++)
        {
            char ch = s[i];
            
            for(it = form.begin() ; it != form.end() ; )
            {
                int j = * it;
                int k = i % j;
                if(s[k] != ch)
                {
                    it = form.erase(it);
                }
                else
                {
                    ++it;
                }
            }
            if(form.empty())
            {
                return false;
            }
        }
        
        return true;
    }
};