/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<int> vec;
    char* Serialize(TreeNode *root) {   
        vec.clear();
        SerializeVec(root);
        int* charList = new int[vec.size()];
        for(int i = 0 ; i < vec.size() ; i ++)
            charList[i] = vec[i];
        return (char*)charList;
    }
    void SerializeVec(TreeNode *root){
        if(!root)
        {
            vec.push_back(0xFFFFFFFF);
            return;
        }
        vec.push_back(root -> val);
        SerializeVec(root -> left);
        SerializeVec(root -> right);
    }
    TreeNode* Deserialize(char *str) {
        if(str == nullptr)
            return nullptr;
        int *p=(int*)str;
        int* i = new int[1];
        i[0] = 0;
        return DeserializeStr(p , i);
    }
    TreeNode* DeserializeStr(int * str, int* index) {
        if(str[index[0]] == 0xFFFFFFFF)
        {
            index[0] += 1;
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(str[index[0]]);
        index[0] ++;
        node -> left = DeserializeStr(str, index);
        node -> right = DeserializeStr(str, index);
        return node;
    }
};