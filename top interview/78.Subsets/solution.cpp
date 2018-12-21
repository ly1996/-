class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res{};
        if(nums.empty()){return res;}
        vector<int> row{};
        vector<vector<int>> prev{};
        res.push_back(row);
        row.push_back(nums[0]);
        res.push_back(row);
        if (nums.size()==1){
            return res;
        }
        
        for(int i=1;i<nums.size();i++){
            prev = res;
            for(int j=0;j<prev.size();j++){
                prev[j].push_back(nums[i]);
                res.push_back(prev[j]);
            }
        }
        return res;
    }
};