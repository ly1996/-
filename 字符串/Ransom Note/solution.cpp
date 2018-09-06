class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int len = magazine.length();
        map<char,int> count;
        
        for(int i = 0 ; i < len ; i ++)
        {
            char ch = magazine[i];
            if(count.find(ch) != count.end())
            {
                count[ch] += 1;
            }
            else
            {
                count.insert(make_pair(ch,1));
            }
        }
        
        for(int i = 0 ; i < ransomNote.length() ; i ++)
        {
            char ch = ransomNote[i];
            if(count.find(ch) == count.end())
            {
                return false;
            }
            else
            {
                if(count[ch] == 0)
                {
                    return false;
                }
                else
                {
                    count[ch] --;
                }
            }
        }
        
        return true;
    }
};