class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n == 0)
            return 0;
        vector<int> vec;
        int current = n;
        while(current > 0)
        {
            int tmp = current / 10;
            int res = current % 10;
            vec.push_back(res);
            current = tmp;
        }

        int len = vec.size();
        if(len == 1)
            if(n >= 1)
                return 1;
            else
                return 0;

        int count = 1;
        for(int i = 2 ; i < len ; i ++)
        {
            int tmp = pow(10,i-1) + count * 9;
            count += tmp;
        }

        int num = vec.back();
        if(num == 1)
            return count + (n - num * pow(10,len-1) + 1) + NumberOf1Between1AndN_Solution(n - num * pow(10,len-1));
        else {
            return count + pow(10,len-1) + (num - 1) * count + NumberOf1Between1AndN_Solution(n - num * pow(10,len-1));
        }
    }
};