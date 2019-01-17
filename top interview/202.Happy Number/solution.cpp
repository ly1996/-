class Solution {
public:
    bool isHappy(int n) {
        if(n == 0)
            return false;
        if(n == 1)
            return true;
        unordered_set<int> s;
        while(true)
        {
            cout << n << endl;
            if(s.find(n) != s.end())
                return false;
            s.insert(n);
            int total = 0;
            while(n != 0)
            {
                total = total + pow(n%10,2);
                n /= 10;
            }
            if(total == 1)
                return true;
            n = total;
        }
    }
};