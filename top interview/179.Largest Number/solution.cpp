class Solution {
public:
    static bool cmp(string a, string b){
        if(a == b)
            return false;
        int len_a = a.size();
        int len_b = b.size();
        int i = 0;
        for(; i< len_a && i < len_b ; i++)
        {
            if(a[i] > b[i])
                return true;
            else if(a[i] < b[i])
                return false;
            else
                continue;
        }
        
        if(i == len_a)
            return cmp(a,b.substr(i));
        return cmp(a.substr(i),b);
            
    }
    string largestNumber(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return "";
        vector<string> num_strings;
        for(int i = 0 ; i < len ; i ++)
        {
            num_strings.push_back(to_string(nums[i]));
            cout << nums[i] << " " ;
        }
        
        sort(num_strings.begin(),num_strings.end(),cmp);
        
        string result = "";
        if(num_strings[0][0] == '0')
            return "0";
        for(string str : num_strings)
            result += str;
        return result;
    }
};