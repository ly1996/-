class Solution {
public:
    int calculate(string s) {
        stack<int> sInt;
        stack<char> sP;
        
        int len = s.size();
        
        int i = 0;
        while(i < len)
        {
            // cout << i << endl;
            if(s[i] == ' ')
            {
                i++;
                continue;
            }
            else if(s[i] >= '0' && s[i] <= '9')
            {
                // cout << "enter" << endl;
                string tmp = "";
                while(i < len && s[i] >= '0' && s[i] <= '9')
                {
                    tmp += s[i];
                    i++;
                }
                int a = atoi(tmp.c_str());
                sInt.push(a);
            }
            else
            {
                if(s[i] == '-' || s[i] == '+')
                {
                    if(sP.empty())
                    {
                        sP.push(s[i]);
                    }
                    else
                    {
                        while(!sP.empty())
                        {
                            char p = sP.top();
                            sP.pop();
                            int num2 = sInt.top();
                            sInt.pop();
                            int num1 = sInt.top();
                            sInt.pop();
                            int result = cal(num1 , num2 , p);
                            sInt.push(result);
                        }
                        sP.push(s[i]);
                    }
                }
                else
                {
                    if(sP.empty())
                    {
                        sP.push(s[i]);
                    }
                    else
                    {
                        if(sP.top() == '-' || sP.top() == '+')
                        {
                            sP.push(s[i]);
                        }
                        else
                        {
                            char p = sP.top();
                            sP.pop();
                            int num2 = sInt.top();
                            sInt.pop();
                            int num1 = sInt.top();
                            sInt.pop();
                            int result = cal(num1 , num2 , p);
                            sInt.push(result);
                            sP.push(s[i]);
                        }
                    }
                }
                i ++;
            }
        }
        
        while(!sP.empty())
        {
            char p = sP.top();
            sP.pop();
            int num2 = sInt.top();
            sInt.pop();
            int num1 = sInt.top();
            sInt.pop();
            int result = cal(num1 , num2 , p);
            sInt.push(result);
        }
        
        return sInt.top();
    }
    
    int cal(int num1 , int num2 , char ch)
    {
        if(ch == '-')
        {
            return num1 - num2;
        }
        else if(ch == '+')
        {
            return num1 +  num2;
        }
        else if(ch == '*')
        {
            return num1 *  num2;
        }
        else
        {
            return num1 / num2;
        }
    }
};