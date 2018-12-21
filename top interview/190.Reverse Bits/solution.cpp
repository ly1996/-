class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i = 0 ; i < 32 ; i ++)
        {
            int tmp = n & 1;
            // cout << tmp << " ";
            if(tmp == 1)
                result = (result << 1) + 1;
            else
                result = result << 1;
            
            n = n >> 1;
        }
        
        return result;
    }
};