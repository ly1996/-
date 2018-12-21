/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while(root != NULL && root -> left != NULL)
        {
            TreeLinkNode* here = root;
            TreeLinkNode* nextRowStart = root -> left;
            TreeLinkNode* prev = NULL;
            
            while(here)
            {
                if(prev != NULL)
                {
                    prev -> next = here -> left;
                }
                
                here -> left -> next = here -> right;
                prev = here -> right;
                here = here -> next;
            }
            
            root = nextRowStart;
        }
    }
};