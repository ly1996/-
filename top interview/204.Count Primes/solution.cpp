class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        //remove 1 and all evens except 2
        int result = n / 2;
        vector<bool> vec(n,false);
        for(int i = 3 ; i * i< n ; i += 2)
        {
            if(!vec[i])
            {
                int step = i * 2;
                for(int j = i * i ; j < n ; j += step)
                {
                    if(!vec[j])
                    {
                        vec[j] = true;
                        result --;
                    }
                }
            }
        }
        
        return result;
    }
};