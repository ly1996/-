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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        
        if (root == NULL)
        {
            return vec;
        }
        
        vector<int> vec_left = inorderTraversal(root -> left);
        vec.insert(vec.end() , vec_left.begin() , vec_left.end());
        
        vec.push_back(root -> val);
        
        vector<int> vec_right = inorderTraversal(root -> right);
        vec.insert(vec.end() , vec_right.begin() , vec_right.end());
        
        return vec;
    }
};