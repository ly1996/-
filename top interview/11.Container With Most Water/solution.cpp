class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        if(size <= 1)
        {
            return 0;
        }
        
        int left = 0;
        int right = size - 1;
        int maxSize = 0;
        while(left < right)
        {
            maxSize = max(maxSize , min(height[left] , height[right]) * (right - left));
            
            if(height[left] < height[right])
            {
                left ++;
            }
            else
            {
                right --;
            }
        }
        return maxSize;
    }
};