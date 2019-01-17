/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "[]";
        string str = "[";
        
        queue<TreeNode*> q;
        q.push(root);
        
        int lastNotNull = 0;
        while(!q.empty())
        {
            int size = q.size();
            int i = 0;
            if(lastNotNull == -1)
                break;
            lastNotNull = -1;

            for(; i < size; i ++)
            {
                TreeNode* tmp = q.front();
                q.pop();
                
                if(tmp == NULL)
                {
                    str += "null,";
                }
                else
                {
                    // cout << tmp -> val << endl;
                    int val = tmp -> val;
                    str = str + to_string(val) + ',';
                    q.push(tmp -> left);
                    if(tmp -> left)
                    {
                        lastNotNull = 1;
                    }
                    q.push(tmp -> right);
                    if(tmp -> right)
                    {
                        lastNotNull = 1;
                    }
                }
            }
        }
        
        // cout << str.substr(0,str.size()-1) + "]" << endl;
        
        return str.substr(0,str.size()-1) + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "[]")
            return NULL;
        int len = data.size();
        
        int i = 1;
        
        TreeNode* root = getNode(data, i, len);
        queue<TreeNode*> q;
        q.push(root);
        
        while(i < len - 1)
        {
            TreeNode * tmp = q.front();
            q.pop();
            TreeNode* left = getNode(data, i, len);
            tmp -> left = left;
            if(left)
            {
                q.push(left);
            }
            
            if(i < len - 1)
            {
                TreeNode* right = getNode(data, i, len);
                tmp -> right = right;
                if(right)
                    q.push(right);
            }
        }
        
        return root;
    }
    
    TreeNode* getNode(string data, int& i, int len){
        string s = "";
        while(i < len - 1 && data[i] != ',')
        {
            s += data[i];
            i ++;
        }
        i ++;
        
        // cout << s << endl;
        
        if(s == "null")
            return NULL;
        TreeNode* node = new TreeNode(atoi(s.c_str()));
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));