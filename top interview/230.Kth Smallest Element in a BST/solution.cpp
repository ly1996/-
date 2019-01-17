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
    int result;
    int count = 0;
    int kthSmallest(TreeNode* root, int k) {
        search(root,k);
        return result;
    }
    
    void search(TreeNode* root, int k){
        if(root -> left)
            search(root -> left, k);
        count ++;
        if(count == k)
        {
            result = root -> val;
            return;
        }
        else if(count < k)
        {
            if(root -> right)
                search(root -> right, k);
        }
        else
            return;
    }
};