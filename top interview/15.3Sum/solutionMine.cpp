#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vecReturn;
        
        int len = nums.size();
        
        if(len < 3)
        {
            return vecReturn;
        }
        
        sort(nums.begin(),nums.end());
        int firstPositiveIndex = -1;
        int firstPositiveNum = -1;
        for(int i = 0 ; i < len ; i ++)
        {
            int tmp = nums[i];
            if(tmp >= 0)
            {
                firstPositiveIndex = i;
                firstPositiveNum = tmp;
                break;
            }
        }
        //将0算作正数
        //两负一正
        for(int i = 0 ; i < firstPositiveIndex - 1; i ++)
        {
            int firstNum = nums[i];
            for(int j = i + 1 ; j < firstPositiveIndex ; j ++)
            {
                int secondNum = nums[j];
                for(int k = firstPositiveIndex ; k < len ; k ++)
                {
                    int thirdNum = nums[k];
                    if(firstNum + secondNum + thirdNum == 0)
                    {
                        vector<int> vec;
                        vec.push_back(firstNum);
                        vec.push_back(secondNum);
                        vec.push_back(thirdNum);
                        vecReturn.push_back(vec);
                    }
                    while(nums[k+1] == thirdNum)
                    {
                        k++;
                    }
                }
                while(nums[j+1] == secondNum)
                {
                    j++;
                }
            }
            while(nums[i+1] == firstNum)
            {
                i++;
            }
        }
        
        //两正一负
        for(int i = firstPositiveIndex ; i < len - 1; i ++)
        {
            int secondNum = nums[i];
            for(int j = i + 1 ; j < len ; j ++)
            {
                int thirdNum = nums[j];
                for(int k = 0 ; k < firstPositiveIndex ; k ++)
                {
                    int firstNum = nums[k];
                    if(firstNum + secondNum + thirdNum == 0)
                    {
                        vector<int> vec;
                        vec.push_back(firstNum);
                        vec.push_back(secondNum);
                        vec.push_back(thirdNum);
                        vecReturn.push_back(vec);
                    }
                    while(nums[k+1] == firstNum)
                    {
                        k++;
                    }
                }
                while(nums[j+1] == thirdNum)
                {
                    j++;
                }
            }
            while(nums[i+1] == secondNum)
            {
                i++;
            }
        }
        
        int numOfZero = 0;
        for(int i = firstPositiveIndex ; i < len; i ++)
        {
            if(nums[i] == 0)
            {
                numOfZero ++;
            }
            else
            {
                break;
            }
        }
        if(numOfZero >= 3)
        {
            vector<int> vec;
            vec.push_back(0);
            vec.push_back(0);
            vec.push_back(0);
            vecReturn.push_back(vec);
        }
        
        return vecReturn;
    }
};