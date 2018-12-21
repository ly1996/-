class Solution {
public:
    int trailingZeroes(int n) {
        long long div = 5;
        int result = 0;
        while(n >= div)
        {
            result += n / div;
            div *= 5;
        }
        
        return result;
    }
};