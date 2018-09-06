class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        
        int **lens = new int * [len1 + 1];
        for(int i = 0 ; i < len1 + 1; i ++)
        {
            lens[i] = new int[len2 + 1];
            for(int j = 0 ; j < len2 + 1 ; j ++)
            {
                lens[i][j] = 0;
            }
        }
        
        for(int i = 0 ; i < len1 + 1 ; i ++)
        {
            lens[i][0] = i;
        }
        
        for(int j = 0 ; j < len2 + 1 ; j ++)
        {
            lens[0][j] = j;
        }
        
        for(int line = 1 ; line <= len1 ; line++)
        {
            for(int col = 1 ; col <= len2 ; col ++)
            {
                if(word1[line - 1] == word2[col - 1])
                {
                    lens[line][col] = lens[line - 1][col - 1];
                }
                else
                {
                    int min = lens[line - 1][col - 1];
                    if(min > lens[line][col - 1])
                    {
                        min = lens[line][col - 1];
                    }
                    if(min > lens[line - 1][col])
                    {
                        min = lens[line - 1][col];
                    }
                    lens[line][col] = min + 1;
                }
            }
        }
        
//         for(int line = 0 ; line <= len1 ; line++)
//         {
//             for(int col = 0 ; col <= len2 ; col ++)
//             {
//                 cout << lens[line][col] << " ";
//             }
//             cout << endl;
//         }
        
        return lens[len1][len2];
    }
};