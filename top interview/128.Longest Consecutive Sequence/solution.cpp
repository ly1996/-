class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> umap;  // value, poz

        int maxi = 0;
        for(int i = 0; i < nums.size(); i++) 
            umap[nums[i]] = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(umap.find(nums[i] - 1) != umap.end())
                continue;
            int len = 1;
            int j = 1;
            while(umap.find(nums[i] + j) != umap.end()) {
                ++len;
                ++j;
            }
            maxi = max(maxi, len);
        }
        return maxi;
    }
};