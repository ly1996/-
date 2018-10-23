class Solution {
public:
    int reverse(int x) {
        if(x == 0)
        {
            return 0;
        }
        if(x == -2147483648)
        {
            return 0;
        }
        
        bool isF = false;
        if(x < 0)
        {
            isF = true;
            x = -x;
        }
        
        int shuzu[10];
        for(int i = 0 ; i < 10 ; i++)
        {
            shuzu[i] = -1;
        }
        int k = 0;
        
        while(true)
        {
            int restX = x / 10;
            int rest = x - restX * 10;
            shuzu[k] = rest;
            k++;
            if(restX == 0)
            {
                break;
            }
            x = restX;
        }
        
        long reverse = 0;
        for(int i = 0 ; i < k ; i ++)
        {
            reverse = reverse * 10 + shuzu[i];
        }
        
        if(reverse <= 2147483647)
        {
            if(isF) return - (int)reverse;
            return (int)reverse;
        }
        else if(reverse == 2147483647)
        {
            if(isF) return - (int)reverse;
            return 0;
        }
        else
        {
            return 0;
        }
    }
};