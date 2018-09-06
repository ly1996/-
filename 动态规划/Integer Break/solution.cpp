class Solution {
public:
    int integerBreak(int n) {
        vector<long> maxProducts(n + 1,1);
        for(int i = 2 ; i <= n ; i ++)
        {
            long maxProduce = 1;
            for(int j = i - 1 ; j >= 1 && j >= i - j ; j --)
            {
                long product_j = maxProducts[j];
                if(j > product_j)
                {
                    product_j = j;
                }
                long product_another = maxProducts[i - j];
                if(i - j > product_another)
                {
                    product_another = i - j;
                }
                if(product_j * product_another > maxProduce)
                {
                    maxProduce = product_j * product_another;
                }
            }
            maxProducts[i] = maxProduce;
        }
        
        return maxProducts[n];
    }
};