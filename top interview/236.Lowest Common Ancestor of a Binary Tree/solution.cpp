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
    vector<TreeNode*> ancestors(TreeNode* current, TreeNode* p){
        if(!current)
            return {};
        if(current == p)
            return {p};
        vector<TreeNode*> left = ancestors(current -> left, p);
        if(left.size() != 0)
        {
            left.push_back(current);
            return left;
        }
        vector<TreeNode*> right = ancestors(current -> right, p);
        if(right.size() != 0)
        {
            right.push_back(current);
            return right;
        }
        
        return {};
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_list = ancestors(root, p);
        vector<TreeNode*> q_list = ancestors(root, q);
        
        // for(int i = 0 ; i < p_list.size() ; i ++)
        // {
        //     cout << p_list[i] -> val << " ";
        // }
        // cout << endl;
        // for(int i = 0 ; i < q_list.size() ; i ++)
        // {
        //     cout << q_list[i] -> val << " ";
        // }
        // cout << endl;
        int i = p_list.size() - 1;
        int j = q_list.size() - 1;
        while(i >= 0 && j >= 0)
        {
            if(p_list[i] != q_list[j])
                return p_list[i+1];
            else
            {
                i --;
                j --;
            }
        }
        
        if(i < 0)
            return p_list[0];
        if(j < 0)
            return q_list[0];
    }
};