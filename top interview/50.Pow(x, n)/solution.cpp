class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
        {
            return 1;
        }
        if(x == 0)
        {
            return 0;
        }
        
        if(n < 0)
        {
            x = 1 / x;
            n = -n;
        }
        
        //now n >= 1 , x != 0
        
        vector<int> vec;
        int tmp = n;
        while(tmp != 0)
        {
            vec.push_back(tmp % 2);
            tmp = tmp / 2;
        }
        
        double result = 1;
        
        for(int i = vec.size() - 1; i >= 0 ; i --)
        {
            if(vec[i] == 0)
            {
                result = result * result;
            }
            else
            {
                result = result * result * x;
            }
        }
        
        return result;
    }
};