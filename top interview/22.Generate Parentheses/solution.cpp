class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        generateString(vec , "" , n , n);
        
        return vec;
    }
    
    void generateString(vector<string> & vec , string s , int count_L , int count_R)
    {
        if(count_L == 0 && count_R == 0)
        {
            vec.push_back(s);
            return;
        }
        
        if(count_L == 0)
        {
            for(int i = 0 ; i < count_R ; i ++)
            {
                s += ')';
            }
            vec.push_back(s);
            return;
        }
        
        if(count_L == count_R)
        {
            generateString(vec , s + '(' , count_L - 1 , count_R);
        }
        else
        {
            generateString(vec , s + '(' , count_L - 1 , count_R);
            generateString(vec , s + ')' , count_L , count_R - 1);
        }
    }
};