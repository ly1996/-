class Solution {
public:
    static bool cmp(string str1, string str2){
        int len1 = str1.size();
        int len2 = str2.size();
        int i = 0;
        while(i < len1 && i < len2)
        {
            if(str1[i] < str2[i])
                return true;
            else if(str1[i] > str2[i])
                return false;
            i++;
        }
        
        if(i == len1 && i == len2)
            return false;
        if(i != len1)
            return cmp(str1.substr(i),str2);
        return cmp(str1,str2.substr(i));
    }
    string PrintMinNumber(vector<int> numbers) {
        int len = numbers.size();
        if(len == 0)
            return "";
        vector<string> vec;
        for(int i = 0 ; i < len ; i ++)
        {
            vec.push_back(to_string(numbers[i]));
        }
        sort(vec.begin(),vec.end(),cmp);
        
        string result = "";
        for(int i = 0 ; i < len ; i++)
            result += vec[i];
       
        return result;
    }
};