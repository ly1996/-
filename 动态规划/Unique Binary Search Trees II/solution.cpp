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
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(n , 1 , n);
    }
    vector<TreeNode*> generateTrees(int count , int start , int end)
    {
        //cout << count << " " << start << " " << end << endl;
        vector<TreeNode*> vec;
        if(count == 1)
        {
            TreeNode * node = new TreeNode(start);
            vec.push_back(node);
            return vec;
        }
        else
        {
            for(int i = start ; i <= end ; i++)
            {
                if(i == start)
                {
                    //cout << "i == start = " << start << endl;
                    vector<TreeNode*> rightVec = generateTrees(count - 1 , start + 1 , end);
                    for(int j = 0 ; j < rightVec.size() ; j++)
                    {
                        TreeNode * node = new TreeNode(i);
                        node -> right = rightVec[j];
                        vec.push_back(node);
                    }
                }
                else if(i == end)
                {
                    vector<TreeNode*> leftVec = generateTrees( count - 1, start , end - 1);
                    for(int j = 0 ; j < leftVec.size() ; j++)
                    {
                        TreeNode * node = new TreeNode(i);
                        node -> left = leftVec[j];
                        vec.push_back(node);
                    }
                }
                else
                {
                    vector<TreeNode*> leftVec = generateTrees(i - start, start , i - 1);
                    vector<TreeNode*> rightVec = generateTrees(end - i , i + 1 , end);
                    for(int m = 0 ; m < leftVec.size() ; m++)
                    {
                        for(int n = 0 ; n < rightVec.size() ; n++)
                        {
                            TreeNode * node = new TreeNode(i);
                            node -> left = leftVec[m];
                            node -> right = rightVec[n];
                            vec.push_back(node);
                        }
                    }
                }
            }
        }
        return vec;
    }
};