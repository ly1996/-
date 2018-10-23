class Solution {
public:
    int myAtoi(string str) {
        int end = str.size() - 1;
        int start = 0;
        while(str[start] == ' ')
        {
            start ++;
        }
        while(str[end] == ' ')
        {
            end -- ;
        }
        
        int i = start;
        bool isF = false;
        if(str[i] == '-')
        {
            isF = true;
            i ++;
        }
        else if(str[start] == '+')
        {
            i ++;
        }
        
        long intReturn = 0;
        for(; i <= end && intReturn <= 2147483647; i ++)
        {
            char ch = str[i];
            if(ch > '9' || ch < '0')
            {
                break;
            }
            int temp = ch - '0';
            intReturn = intReturn * 10 + temp;
        }
        
        cout << intReturn;
        
        if(isF)
        {
            if(intReturn > 2147483648)
            {
                return -2147483648;
            }
            return -intReturn;
        }
        else
        {
            if(intReturn > 2147483647)
            {
                return 2147483647;
            }
            return intReturn;
        }
    }
};