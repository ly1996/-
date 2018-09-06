class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        if(len == 0 || len == 1)
        {
            return 0;
        }
        
        int ** maxLen = new int *[len];
        int ** start = new int *[len];
        int ** end = new int *[len];
        
        for(int i = 0 ; i < len ; i ++)
        {
            maxLen[i] = new int[len];
            start[i] = new int[len];
            end[i] = new int[len];
            for(int j = 0 ; j < len ; j ++)
            {
                maxLen[i][j] = 0;
                // start[i][j] = -1;
                // end[i][j] = -1;
            }
        }
        
        for(int j = 0 ; j + 1 < len ; j ++)
        {
            if(s[j] == '(' && s[j + 1] == ')')
            {
                maxLen[j][j+1] = 2;
                start[j][j+1] = j;
                end[j][j+1] = j+1;
                
            }
        }
        
        for(int i = 3 ; i <= len ; i ++)
        {
            //i:字符串长度
            for(int j = 0 ; j + i - 1 < len ; j ++)
            {
                //j:字符串起始位置
                int len1 = maxLen[j][j + i - 2];
                int newLen1 = len1;
                int newStart1 = start[j][j + i - 2];
                int newEnd1 = end[j][j + i - 2];
                
                if(len1 == 0)
                {
                    if(s[j + i - 1] == ')' && s[j + i - 2] == '(')
                    {
                        newLen1 = 2;
                        newStart1 = j + i - 2;
                        newEnd1 = j + i - 1;
                    }
                }
                else
                {
                    if(s[j + i - 1] == ')')
                    {
                        int startIndex = start[j][j + i - 2];
                        int endIndex = end[j][j + i - 2];
                        if(endIndex == j + i - 2)
                        {
                            if( startIndex != j )
                            {
                                if(s[startIndex - 1] =='(')
                                {
                                    newLen1 += 2;
                                    newStart1 = startIndex - 1;
                                    newEnd1 = j + i - 1;
                                
                                    if(startIndex - 2 > j && end[j][startIndex - 2] == startIndex - 2)
                                    {
                                        newLen1 += maxLen[j][startIndex - 2];
                                        newStart1 = start[j][startIndex - 2];
                                    }
                                }
                            } 
                        }
                        else
                        {
                            if(start[endIndex + 1][j + i - 1] == endIndex + 1 && end[endIndex + 1][j + i - 1] == j + i - 1)
                            {
                                newLen1 = len1 + maxLen[endIndex + 1][j + i - 1];
                                newStart1 = startIndex;
                                newEnd1 = j + i - 1;
                            }
                            else
                            {
                                if(maxLen[endIndex + 1][j + i - 1] > len1)
                                {
                                    newLen1 = maxLen[endIndex + 1][j + i - 1];
                                    newStart1 = start[endIndex + 1][j + i - 1];
                                    newEnd1 = end[endIndex + 1][j + i - 1];
                                }
                            }
                        }
                    }
                }
                
                int len2 = maxLen[j + 1][j + i - 1];
                int newLen2 = len2;
                int newStart2 = start[j + 1][j + i - 1];
                int newEnd2 = end[j + 1][j + i - 1];
                
//                 if(len2 == 0)
//                 {
//                     if(s[j] == '(' && s[j + 1] == ')')
//                     {
//                         newLen2 = 2;
//                         newStart2 = j ;
//                         newEnd2 = j + 1;
//                     }
//                 }
//                 else
//                 {
//                     if(s[j] == '(')
//                     {
//                         int startIndex = start[j + 1][j + i - 1];
//                         int endIndex = end[j + 1][j + i - 1];
                        
//                         if(startIndex == j + 1 && endIndex != j + i - 1)
//                         {
//                             if(s[endIndex + 1] == ')')
//                             {
//                                 newLen2 += 2;
//                                 newStart2 = j;
//                                 newEnd2 = endIndex + 1;
//                                 if(endIndex + 2 < j + i - 1 && start[endIndex + 2][j + i - 1] == endIndex + 2)
//                                 {
//                                     newLen2 += maxLen[endIndex + 2][j + i - 1] ;
//                                     newEnd2 = end[endIndex + 2][j + i - 1] ;
//                                 }
//                             }
//                         }
                        
//                         if(startIndex != j + 1)
//                         {   
//                             if(end[j][startIndex - 1] == startIndex - 1 && start[j][startIndex - 1] == j)
//                             {
//                                 newLen2 = len2 + maxLen[endIndex + 1][j + i - 1];
//                                 newStart2 = j;
//                             }
//                             else
//                             {
//                                 if(maxLen[j][startIndex - 1] > len2)
//                                 {
//                                     newLen2 = maxLen[j][startIndex - 1];
//                                     newStart2 = start[j][startIndex - 1];
//                                     newEnd2 = end[j][startIndex - 1];
//                                 }
//                             }
//                         }
//                     }
                // }
                
                // if(s == "))(())()((((((())(()))((())(((((((()))())((((())())(()())))))))))((()((()(()(()()((()()()(()()()))(()()(()(())())))()())()(((((")
                // {
                //     if(newLen1 != newLen2)
                //     {
                //         cout <<j <<":" << j + i - 1 << ":len1:" << newLen1 << " ; "<< newStart1 << " ; " << newEnd1 << endl;
                //         cout <<j <<":" << j + i - 1 << ":len2:" << newLen2 << " ; "<< newStart2 << " ; " << newEnd2 << endl;
                //     }
                // }
                
                if(newLen1 >= newLen2)
                {
                    maxLen[j][j+i-1] = newLen1;
                    start[j][j+i-1] = newStart1;
                    end[j][j+i-1] = newEnd1;
                }
                else
                {
                    maxLen[j][j+i-1] = newLen2;
                    start[j][j+i-1] = newStart2;
                    end[j][j+i-1] = newEnd2;
                }
            }
        }
        
        return maxLen[0][len - 1];
    }
};