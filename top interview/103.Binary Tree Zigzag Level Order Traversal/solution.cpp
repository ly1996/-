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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
        {
            return result;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int h = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> vec(size,0);
            int index;
            int add;
            if(h % 2 == 0)
            {
                index = 0;
                add = 1;
            }
            else
            {
                index = size - 1;
                add = -1;
            }
            
            for(int i = 0 ; i < size ; i ++)
            {
                TreeNode* tmp = q.front();
                q.pop();
                
                vec[index] = tmp -> val;
                index += add;
                
                if(tmp -> left)
                {
                    q.push(tmp -> left);
                }
                if(tmp -> right)
                {
                    q.push(tmp -> right);
                }
            }
            
            result.push_back(vec);
            h ++;
        }
        
        return result;
    }
};