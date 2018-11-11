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
    bool isSymmetric(TreeNode* root) {
        if(!root)
        {
            return true;
        }
        if(!root -> left && !root -> right)
        {
            return true;
        }
        queue<TreeNode*> q;
        
        q.push(root -> left);
        q.push(root -> right);
        
        while(!q.empty())
        {
            TreeNode* m = q.front();
            q.pop();
            TreeNode* n = q.front();
            q.pop();
            
            if(!m && !n)
            {
                continue;
            }
            if(!m || !n)
            {
                return false;
            }
            if(m -> val != n -> val)
            {
                return false;
            }
            
            q.push(m -> left);
            q.push(n -> right);
            
            q.push(m -> right);
            q.push(n -> left);
        }
        
        return true;
    }
};