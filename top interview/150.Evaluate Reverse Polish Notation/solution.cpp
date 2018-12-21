class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int sum = 0;
        for(int i = 0 ; i < tokens.size() ; i++)
        {
            string tmp = tokens[i];
            if(tmp == "*" || tmp == "-" || tmp == "/" || tmp == "+")
            {
                int i2 = s.top();
                s.pop();
                int i1 = s.top();
                s.pop();
                if(tmp == "*")
                {
                    sum = i1 * i2;
                }
                else if(tmp == "-")
                {
                    sum = i1 - i2;
                }
                else if(tmp == "/")
                {
                    sum = i1 / i2;
                }
                else
                {
                    sum = i1 + i2;
                }
                s.push(sum);
            }
            else
            {
                s.push(atoi(tmp.c_str()));
            }
        }
        return s.top();
    }
    
    int intToString(string s){
        stringstream ss;
        ss << s;
        int i ;
        ss >> i;
        return i;
    }
};