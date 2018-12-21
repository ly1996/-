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
    bool isValidBST(TreeNode* root) {
        if(!root)
        {
            return true;
        }
        stack<TreeNode*> st;
        TreeNode* tmp = root;
        while(tmp)
        {
            st.push(tmp);
            tmp = tmp -> left;
        }
        
        long pre = (long)INT_MIN - 1;
        while(!st.empty())
        {
            tmp = st.top();
            st.pop();
            
            // cout << tmp -> val << " " << pre << endl;
            
            if(pre >= tmp -> val)
            {
                return false;
            }
            pre = tmp -> val;
            
            tmp = tmp -> right;
            while(tmp)
            {
                st.push(tmp);
                tmp = tmp -> left;
            }
        }
        
        return true;
    }
};