class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (abs(res) > INT_MAX / 10) return 0; //如果res == INT_MAX / 10，由于x为10位数时，必为1或者2开头，所以没问题。
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};