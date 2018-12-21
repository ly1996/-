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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
        {
            return result;
        }
        queue<pair<TreeNode*,int>> q;
        
        q.push(pair<TreeNode*,int>(root,0));
        
        vector<int> vec;
        int level = 0;
        
        while(!q.empty())
        {
            pair<TreeNode*,int> tmp = q.front();
            q.pop();
            
            if(tmp.second != level)
            {
                result.push_back(vec);
                vec = {};
                level += 1;
            }
            
            vec.push_back(tmp.first -> val);
            if(tmp.first -> left)
            {
                q.push(pair<TreeNode*,int>(tmp.first -> left, tmp.second + 1));
            }
            if(tmp.first -> right)
            {
                q.push(pair<TreeNode*,int>(tmp.first -> right, tmp.second + 1));
            }
        }
        
        result.push_back(vec);
        
        return result;
    }
};