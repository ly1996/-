class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if(len <= 1)
            return;
        k = k % len;
        if(k == 0)
            return;
        int totalCount = 0;
        int i = 0;
        while(totalCount < len)
        {
            int start = i;
            int tmp = nums[i];
            int steps = 0;
            while(steps == 0 || start != i)
            {
                int next = start + k;
                if(next >= len)
                    next -= len;
                int ano = nums[next];
                nums[next] = tmp;
                tmp = ano;
                start = next;
                steps ++;
            }
            
            totalCount += steps;
            i ++;
        }
    }
};