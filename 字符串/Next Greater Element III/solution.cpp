class Solution {
public:
    static bool compare(int a,int b)
    {
        return a>b; //降序
    }
    int nextGreaterElement(int n) {
        vector<int> vec;
        
        int tmp = n;
        while(true)
        {
            int rest = tmp % 10;
            vec.push_back(rest);
            tmp = tmp / 10;
            if(tmp == 0)
            {
                break;
            }
        }
        
        int end = 0;
        while(end + 1 < vec.size() && vec[end] <= vec[end + 1])
        {
            end ++;
        }
        
        if(end == vec.size() - 1)
        {
            return -1;
        }
        
        sort(vec.begin() , vec.begin() + end + 1, compare);
        
        // for(int i = 0 ; i < vec.size() ; i ++)
        // {
        //     cout << vec[i] << " " ;
        // }
        
        for(int j = end ; j >= 0 ; j --)
        {
            if(vec[j] > vec[end + 1]){
                int t = vec[j];
                vec[j] = vec[end + 1];
                vec[end + 1] = t;
                break;
            }
        }
        
        int result = 0;
        for(int i = 0 ; i < vec.size() ; i ++)
        {
            result += vec[i] * pow(10,i);
        }
        
        if(result < 0)
        {
            return -1;
        }
        
        return result;
    }
};