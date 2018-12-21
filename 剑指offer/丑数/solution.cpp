class Solution {
public:
    int nthUglyNumber(int index) {
        if(index <= 0)
            return 0;
        vector<int> vec(1,1);
        
        int i = 0, j = 0, k = 0;
        int pos = 1;
        while(pos < index)
        {
            pos ++;
            int minNum = min(vec[i] * 2 , min(vec[j] * 3 , vec[k] * 5));
            vec.push_back(minNum);
            
            if(minNum == vec[i] * 2)
                i ++;
            if(minNum == vec[j] * 3)
                j ++;
            if(minNum == vec[k] * 5)
                k ++;
        }
        
        return vec[index - 1];
    }
};