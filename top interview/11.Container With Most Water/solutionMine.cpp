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
            // cout << left << " " << right << endl;
            maxSize = max(maxSize , min(height[left] , height[right]) * (right - left));
            
            if(height[left] < height[right])
            {
                while(height[left + 1] < height[left])
                {
                    left ++;
                }
                left ++;
            }
            else
            {
                while(height[right - 1] < height[right])
                {
                    right --;
                }
                right --;
            }
        }
        return maxSize;
    }
};