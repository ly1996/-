class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int num : nums)
        {
            auto result = s.insert(num);
            if(result.second == false)
                return true;
        }
        return false;
    }
};