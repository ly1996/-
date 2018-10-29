class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> numbers;
        for(int i = 0 ; i < nums.size() ; i ++)
        {
            numbers.push_back(-1);
        }
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int tmp = nums[i];
            if(tmp > 0)
            {
                numbers[tmp -1] = 1;
            }
        }
        for(int i = 0 ; i < nums.size() ; i ++)
        {
            int tmp = numbers[i];
            cout << tmp << endl;
            if(tmp < 0)
            return i + 1;
        }
        return nums.size() + 1;
    }
};