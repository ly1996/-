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
    pair<bool,pair<int,int>> isValid(TreeNode* root)
    {   
        int minNumber, maxNumber;
        if(root -> left)
        {
            pair<bool,pair<int,int>> tmp = isValid(root -> left);
            
            if(!tmp.first)
            {
                return pair<bool,pair<int,int>>(false,pair<int,int>(0,0));
            }
            if(tmp.second.second >= root -> val)
            {
                return pair<bool,pair<int,int>>(false,pair<int,int>(0,0));
            }
            
            minNumber = tmp.second.first;
        }
        else
        {
            minNumber = root -> val;
        }
        
        if(root -> right)
        {
            pair<bool,pair<int,int>> tmp = isValid(root -> right);
            if(!tmp.first)
            {
                return pair<bool,pair<int,int>>(false,pair<int,int>(0,0));
            }
            if(tmp.second.first <= root -> val)
            {
                return pair<bool,pair<int,int>>(false,pair<int,int>(0,0));
            }
            maxNumber = tmp.second.second;
        }
        else
        {
            maxNumber = root -> val;
        }
        
        return pair<bool,pair<int,int>>(true,pair<int,int>(minNumber,maxNumber));
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root)
        {
            return true;
        }
        return isValid(root).first;
    }
};