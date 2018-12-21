class Solution {
public:
    bool match(char* ss, char* pp)
    {
        if(ss == nullptr || pp == nullptr)
            return false;
        if(ss[0] == '\0' && pp[0] == '\0')
            return true;
        if(pp[0] == '\0')
            return false;
        if(ss[0] == '\0')
        {
            int i =0;
            while(pp[i+1] == '*')
            {
                i += 2;
            }
            return pp[i] == '\0';
        }
        
        if(pp[1] == '*')
        {
            if(ss[0] == pp[0] || pp[0] == '.')
            {
                return match(ss,pp + 2) || match(ss + 1, pp + 2) || match(ss + 1, pp);
            }
            else
            {
                return match(ss,pp + 2);
            }
        }
        if(ss[0] == pp[0] || pp[0] == '.')
            return match(ss + 1, pp + 1);
        return false;
    }
};