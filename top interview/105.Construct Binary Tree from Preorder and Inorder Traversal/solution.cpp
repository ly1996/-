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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0)
        {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[0]);
        
        queue<TreeNode*> qOfNode;
        qOfNode.push(root);
        queue<pair<int,int>> qOfPreVec;
        qOfPreVec.push(make_pair(0,preorder.size() - 1));
        queue<pair<int,int>> qOfInVec;
        qOfInVec.push(make_pair(0,preorder.size() - 1));
              
        while(!qOfNode.empty())
        {
            TreeNode* node =  qOfNode.front();
            qOfNode.pop();
            
            pair<int,int> prePair = qOfPreVec.front();
            qOfPreVec.pop();
            int start1 = prePair.first;
            int end1 = prePair.second;
            
            pair<int,int> inPair = qOfInVec.front();
            qOfInVec.pop();
            int start2 = inPair.first;
            int end2 = inPair.second;
            
            // int index = inorder.find(node -> val);
            
            vector <int>::iterator iElement = find(inorder.begin(),inorder.end(),node -> val);
            int index = distance(inorder.begin(),iElement);
            
            if(index > start2)
            {
                TreeNode* leftNode = new TreeNode(preorder[start1 + 1]);
                node -> left = leftNode;
                qOfNode.push(leftNode);
                
                int len = index - 1 - start2 + 1;
                qOfPreVec.push(make_pair(start1 + 1,start1 + index - start2));
                qOfInVec.push(make_pair(start2,index - 1));
            }
            if(index < end2)
            {
                TreeNode* rightNode = new TreeNode(preorder[start1 + index - start2 + 1]);
                node -> right = rightNode;
                qOfNode.push(rightNode);
                
                qOfPreVec.push(make_pair(start1 + index - start2 + 1,end1));
                qOfInVec.push(make_pair(index + 1,end2));
            }
        }
        
        return root;
    }
};