class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // nums.insert(nums.begin(),INT_MIN);
        // nums.push_back(INT_MIN);
        int left = 0;
        int right = nums.size() - 1;
        
        while(left + 1< right)
        {
            int mid = (left + right) / 2;
            
            if((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == nums.size() - 1 || nums[mid] > nums[mid + 1]))
            {
                return mid;
            }
            else
            {
                if(nums[mid] < nums[mid + 1])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            
            // cout << left << " " << right << endl;
        }
        
        if(nums[left] >= nums[right])
        {
            return left;
        }
        return right;
    }
};