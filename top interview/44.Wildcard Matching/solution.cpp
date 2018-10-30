class Solution {
public:
    bool isMatch(string s, string p) {
        int len_s = s.length();
        int len_p = p.length();
        
        int s_index = 0;
        int p_index = 0;
        
        //标记*的位置。
        int star = -1;
        //标记上一次和*后一位char开始匹配的地方
        int ss_index = -1;
        while(s_index < len_s)
        {
            // cout << s_index << " " << p_index << endl;
            if(s[s_index] == p[p_index] || p[p_index] == '?')
            {
                s_index ++;
                p_index ++;
                continue;
            }
            if(p[p_index] == '*')
            {
                star = p_index;
                p_index ++;
                ss_index = s_index;
                continue;
            }
            if(star >= 0)
            {
                p_index = star + 1;
                s_index = ++ss_index;
                continue;
            }
            
            return false;
        }
        
        while(p_index < len_p && p[p_index] == '*')
        {
            p_index ++;
        }
        
        return p_index == len_p;
    }
};