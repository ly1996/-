class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len = A.size();
        vector<int> vec(len,1);
        if(len == 0)
            return vec;
        for(int i = 1 ; i < len ; i ++)
        {
            vec[i] = vec[i - 1] * A[i - 1];
        }
        
        int tmp = 1;
        for(int i = len - 2 ; i >= 0 ; i --)
        {
            tmp = tmp * A[i + 1];
            vec[i] *= tmp;
        }
        
        return vec;
    }
};