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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
        {
            vector<TreeNode*> trees;
            return trees;
        }
        
        vector<int> vec;
        for(int i = 1 ; i <= n ; i ++)
        {
            vec.push_back(i);
        }
        
        return generateByVec(vec , 0 , n - 1);
    }
    
    vector<TreeNode*> generateByVec(vector<int> vec , int begin , int end) {
        vector<TreeNode*> trees;
        
        if(begin > end)
        {
            trees.push_back(NULL);
            return trees;
        }
        
        for(int i = begin ; i <=  end ; i ++)
        {
            int left = i - 1;
            int right = i + 1;
            vector<TreeNode*> leftTrees = generateByVec(vec , begin , left);
            vector<TreeNode*> rightTrees = generateByVec(vec , right , end);
            
            for(int j = 0 ; j < leftTrees.size() ; j ++)
            {
                for(int k = 0 ; k < rightTrees.size() ; k ++)
                {
                    TreeNode* tmpNode = new TreeNode(vec[i]);
                    tmpNode->left = leftTrees[j];
                    tmpNode->right = rightTrees[k];
                    trees.push_back(tmpNode);
                }
            }
        }
        
        return trees;
    }
};