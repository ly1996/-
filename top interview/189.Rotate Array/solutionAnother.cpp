class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if(len <= 1)
            return;
        k = k % len;
        if(k == 0)
            return;
        reverse(nums,0,len-1);
        reverse(nums,0,k-1);
        reverse(nums,k,len-1);
    }
    
    void reverse(vector<int>& nums, int start, int end){
        while(start < end)
        {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start ++;
            end --;
        }
    }
};