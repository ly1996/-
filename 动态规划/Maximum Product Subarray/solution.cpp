class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        
        int maxNum = nums[0];
        vector<int> product;
        for(int i = 0 ; i < len ; i ++)
        {
            int num = nums[i];
            if(num > maxNum)
            {
                maxNum = num;
            }
            product.push_back(num);
        }
        
        for(int i = 2 ; i <= len ; i ++)
        {
            //i代表乘积长度
            for(int j = len - 1 ; j >= i - 2 ; j -- )
            {
                int tmp_product = product[j - 1] * nums[j];
                if(tmp_product > maxNum)
                {
                    maxNum = tmp_product;
                }
                product[j] = tmp_product;
            }
            
//             for(int j = 0 ; j < len ; j ++)
//             {
//                 cout << product[j] << " ";
//             }
//             cout << endl;
        }
        
        return maxNum;
    }
};