class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 0;
        
        if(dividend == -2147483648)
        {
            if(divisor == -1)
            {
                return 2147483647;
            }
        }
        
        long a = abs((long)dividend);
        long b = abs((long)divisor);
        
        while(a >= b)
        {
            long c = b;
            for(int i = 0 ; a >= c && a > 0; i ++ , c <<= 1)
            {
                a -= c;
                result += 1 << i;
            }
        }
        
        return ((dividend ^ divisor) >> 31)? (-result):(result);
    }
};