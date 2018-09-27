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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> vecList;
        
        if(!root)
        {
            return vecList;
        }
        
        queue<TreeNode*> nodes;
        queue<vector<int>> sums;
        
        vector<int> vec;
        vec.push_back(root -> val);
        vec.push_back(root -> val);
        sums.push(vec);
        nodes.push(root);
        
        while(!sums.empty())
        {
            vector<int> tmpVec = sums.front();
            TreeNode* node =  nodes.front();
            
            sums.pop();
            nodes.pop();
            
            if(node -> left == NULL && node -> right == NULL)
            {
                if(tmpVec[0] == sum)
                {
                    tmpVec.erase(tmpVec.begin());
                    vecList.push_back(tmpVec);
                }
                continue;
            }
            
            if(node -> left != NULL)
            {
                vector<int> newVec(tmpVec);
                int newSum = tmpVec[0] + node -> left -> val;
                newVec[0] = newSum;
                newVec.push_back(node -> left -> val);
                sums.push(newVec);
                nodes.push(node -> left);
            }
            if(node -> right != NULL)
            {
                vector<int> newVec(tmpVec);
                int newSum = tmpVec[0] + node -> right -> val;
                newVec[0] = newSum;
                newVec.push_back(node -> right -> val);
                sums.push(newVec);
                nodes.push(node -> right);
            }
        }
        
        return vecList;
    }
};