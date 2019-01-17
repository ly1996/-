class Solution {
public:
    int partition(vector<int>& nums, int lo, int hi){ 
        int pivot=lo++;  // always select left as pivot
        while(lo<=hi){
            if (nums[lo]<nums[pivot]) swap(nums[lo], nums[hi--]);
            else lo++;
        }
        swap(nums[pivot], nums[hi]); 
        return hi;
    }
    // int partition(vector<int>& nums, int p, int r){
    //     int x = nums[r];
    //     int i = p - 1;
    //     for(int j = p ; j < r ; j ++)
    //     {
    //         if(nums[j] > x)
    //         {
    //             i += 1;
    //             swap(nums[i],nums[j]);
    //         }
    //     }
    //     swap(nums[i + 1],nums[r]);
    //     return i + 1;
    // }
    int findKth(vector<int>& nums, int p, int r, int k){
        if(p == r)
            return nums[p];
        int q = partition(nums, p, r);
        // cout << p << " " << r << " " << q << endl;
        if(q == k - 1)
            return nums[q];
        else if(q < k - 1)
            return findKth(nums,q+1,r,k);
        else
            return findKth(nums,p,q-1,k);
        // int k = q - p + 1;
        // if(k == i)
        //     return nums[q];
        // else if(k < i)
        // {
        //     return findKth(nums,q+1,r,i-k);
        // }
        // else
        //     return findKth(nums,p,q-1,i);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return findKth(nums, 0, nums.size() - 1, k);
    }
};