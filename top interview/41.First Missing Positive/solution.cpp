class Solution {
public:
    void Swap(vector<int>& nums, int i , int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        int i = 0;
        while(i < size)
        {
            while(nums[i] > 0 && nums[i] <= size && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[i], nums[nums[i]-1]);
                // Swap(nums, i , nums[i] - 1);
            }
            i ++;
        }
        
        for(int i = 0 ; i < size ; i ++)
        {
            if(nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        
        return size + 1;
    }
};