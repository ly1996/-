class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1)
        {
            return x;
        }
        
        int l = 1;
        int r = x;
        
        while(l <= r)
        {
            int mid = (l + r) / 2;
            
            if(x / mid == mid)
            {
                return mid;
            }
            else if(x / mid < mid)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        
        return l - 1;//e.g.:8 left = 1, right = 3 -> left = 1, right = 2 -> left = 2, right = 2 -> left = 3, right = 2(break)
    }
};