class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        
        int left = 0;
        int right = len - 1;
        
        vector<int> count(256 , 0);
        
        for(int i = 1 ; i <= 26 ; i ++)
        {
            count['a' + i - 1] = i;
            count['A' + i - 1] = i;
        }
        
        for(int i = 1 ; i <= 10 ; i ++)
        {
            count['0' + i - 1] = -i;
        }
        
        while(true)
        {
            while(left < len && count[s[left]] == 0)
            {
                left ++;
            }
            
            while(right >= 0 && count[s[right]] == 0)
            {
                right --;
            }
            
            if(left >= right)
            {
                return true;
            }
            
            if(count[s[left]] != count[s[right]])
            {
                return false;
            }
            
            left ++;
            right --;
        }
    }
};