class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        if(s == "")
        {
            return 0;
        }
        
        int ** counts = new int *[m];
        for(int i = 0 ; i < m ; i ++)
        {
            counts[i] = new int[n];
            for(int j = 0 ; j < n ; j ++)
            {
                counts[i][j] = 0;
            }
        }
        
        if(s[0] == t[0])
        {
            counts[0][0] = 1;
        }
        else
        {
            counts[0][0] = 0;
        }
        
        for(int i = 1; i < m ; i ++)
        {
            if(s[i] == t[0])
            {
                // cout << i << endl;
                counts[i][0] = counts[i - 1][0] + 1; 
            }
            else
            {
                counts[i][0] = counts[i - 1][0];
            }
        }
        
        for(int i = 1 ; i < m ; i ++)
        {
            for(int j = 1 ; j <= i && j < n ; j ++)
            {
                if(s[i] == t[j])
                {
                    counts[i][j] = counts[i - 1][j] + counts[i - 1][j - 1];
                }
                else
                {
                    counts[i][j] = counts[i - 1][j];
                }
            }
        }
        // for(int i = 0 ; i < m ; i ++)
        // {
        //     for(int j = 0 ; j <= i && j < n ; j ++)
        //     {
        //         cout << counts[i][j] <<" ";
        //     }
        //     cout << endl;
        // }
    
        return counts[m - 1][n - 1];
    }
};