class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> vec = {-1,-1};
        
        if(nums.size() == 0)
        {
            return vec;
        }
        
        int left = 0;
        int right = nums.size();
        
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
            
            // cout << left << " " << right << endl;
        }
        
        if(left != nums.size() && nums[left] == target)
        {
            vec[0] = left;
        }
        else
        {
            return vec;
        }
        
        // left = -1;
        right = nums.size() - 1;
        while(left < right)
        {
            int mid = (left + right) / 2 + 1;
            if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid;
            }
            
            // cout << left << " " << right << endl;
        }
        
        vec[1] = left;
        
        return vec;
    }
};