/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int max = INT_MIN;
    int maxPathSum(TreeNode* root) {
        max = root -> val;
        maxPathSumWithRoot(root);
        
        return max;
    }
    
    int maxPathSumWithRoot(TreeNode* root)
    {
        if(!root)
        {
            return INT_MIN;
        }
        
        int leftSum = maxPathSumWithRoot(root -> left);
        int rightSum = maxPathSumWithRoot(root -> right);
        
        int tmpMax = leftSum;
        if(rightSum > tmpMax)
        {
            tmpMax = rightSum;
        }
        
        int maxSum = root -> val;
        if(leftSum > 0)
        {
            maxSum += leftSum;
        }
        if(rightSum > 0)
        {
            maxSum += rightSum;
        }
        if(root -> val < 0)
        {
            if(tmpMax > maxSum)
            {
                maxSum = tmpMax;
            }
        }
    
        // cout << maxSum << endl;
        if(maxSum > max)
        {
            max = maxSum;
        }
        
        int maxSumWithRoot = root -> val;
        if(leftSum <= 0 && rightSum <= 0)
        {
            
        }
        else if(leftSum > rightSum)
        {
            maxSumWithRoot += leftSum;
        }
        else
        {
            maxSumWithRoot += rightSum;
        }
        
        return maxSumWithRoot;
    }
};