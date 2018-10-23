class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	//-1代表不存在
        vector<int> m(256, -1);
        int res = 0, left = -1;
        for (int i = 0; i < s.size(); ++i) {
		//更新left
            left = max(left, m[s[i]]);
		//更新hash表
            m[s[i]] = i;
		//计算长度更新最大值
            res = max(res, i - left);
        }
        return res;
    }
};