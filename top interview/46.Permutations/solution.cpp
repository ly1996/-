class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        
        vector<vector<int>> vecList;
        vector<int> vec(len,1);
        
        constructVec(vecList,vec,nums,0);
        
        return vecList;
    }
    
    void constructVec(vector<vector<int>> & vecList , vector<int> & vec , vector<int>& nums , int index)
    {
        int len = vec.size();
        
        if(len == index)
        {
            vecList.push_back(vec);
            return;
        }
        
        for(int i = 0 ; i < len - index ; i ++)
        {
            vec[index] = nums[i];
            swap(nums[i],nums[len - index - 1]);
            constructVec(vecList,vec,nums,index + 1);
            swap(nums[i],nums[len - index - 1]);
        }
    }
};