class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret(2,-1);
        map<int, int> m;    //value->index map
        for(int i = 0; i < numbers.size(); i ++)
        {
            if(m.find(target-numbers[i]) == m.end())
            //target-numbers[i] not appeared
                m[numbers[i]] = i;
            else
            {
                ret[0] = m[target-numbers[i]]; 
                ret[1] = i;
                return ret;
            }
        }
        return ret;
    }
};