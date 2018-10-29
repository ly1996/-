#define MAX_STACK_SIZE 100
class Solution {
public:
    map<char,char> m = {{')','('},{'}','{'},{']','['}};
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0 ; i < s.size() ; i ++)
        {
            char ch = s[i];
            if(ch == '(' || ch == '[' || ch == '{')
            {
                st.push(ch);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }
                char tmp = st.top();
                // cout << ch << ":" << tmp << endl;
                st.pop();
                if(tmp != m[ch])
                {
                    return false;
                }
            }
        }
        if(!st.empty())
        {
            return false;
        }
        return true;
    }
};