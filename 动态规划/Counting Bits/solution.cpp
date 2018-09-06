class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>counts(num + 1 , 0);
        if(num == 1)
        {
            counts[1] = 1;
            return counts;
        }
        
        counts[1] = 1;
        int start = 1;
        
        for(int i = 2 ; i <= num ; i ++)
        {
            if(i == start * 2)
            {
                counts[i] = 1;
                start *= 2;
            }
            else
            {
                counts[i] = 1 + counts[i - start];
            }
        }
        
        return counts;
    }
};