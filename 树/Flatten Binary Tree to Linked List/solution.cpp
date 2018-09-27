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
    void flatten(TreeNode* root) {
        if(!root)
        {
            return;
        }
        
        TreeNode* cur = NULL;
        
        stack<TreeNode*> s;
        
        s.push(root);
        while(!s.empty())
        {
            TreeNode* node = s.top();
            s.pop();
            
            if(node -> right)
            {
                s.push(node -> right);
            }
            if(node -> left)
            {
                s.push(node -> left);
            }
            
            if(cur == NULL)
            {
                cur = node;
            }
            else
            {
                cur -> right = node;
                cur -> left = NULL;
                cur = node;
            }
        }
    }
};