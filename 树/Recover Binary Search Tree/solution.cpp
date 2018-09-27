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
    TreeNode* first;
    TreeNode* second;
    TreeNode* pre;
    void recoverTree(TreeNode* root) {
        inorder(root);
        int val = first -> val;
        first -> val = second -> val;
        second -> val = val;
    }
    
    void inorder(TreeNode* root){
        if(!root)
        {
            return;
        }
        inorder(root -> left);
        if(!pre)
        {
            pre = root;
        }
        else
        {
            if(pre -> val > root -> val)
            {
                if(!first)
                {
                    first = pre;
                }
                second = root;
            }
            pre = root;
        }
        inorder(root -> right);
    }
};