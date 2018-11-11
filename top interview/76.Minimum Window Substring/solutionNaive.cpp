class Node
{
public:
    char ch;
    int index;
    Node * right;
    Node * left;

    Node(char c, int in){
        this -> ch = c;
        this -> index = in;
        right = left = NULL;
    }

    Node() {}
};

class Solution {
public:
    string minWindow(string s, string t) {
        int minLen = INT_MAX;
        int start = -1;
        int end = -1;
        Node * head = new Node();
        Node * current = head;

        int totalCount = t.size();
        map<char,int> mCount;
        set<char> charSet;
        for(int i = 0 ; i < t.size() ; i ++)
        {
            char ch = t[i];
            charSet.insert(ch);
            if(mCount.find(ch) == mCount.end())
            {
                mCount[ch] = 1;
            }
            else
            {
                mCount[ch] = mCount[ch] + 1;
            }
        }

        map<char,vector<Node*>> m;

        for(int i = 0 ; i < s.size() ; i ++)
        {
            char ch = s[i];

            if(charSet.find(ch) == charSet.end())
            {
                continue;
            }

            Node* node = new Node(ch,i);
            current -> right = node;
            node -> left = current;
            current = node;

            if(m.find(ch) == m.end())
            {
                vector<Node*> vec;
                vec.push_back(node);
                m[ch] = vec;
            }
            else
            {
                m[ch].push_back(node);
            }

            int leftCount = mCount[ch];

            if(leftCount != 0)
            {
                mCount[ch] --;
                totalCount --;
            }
            else
            {
                vector<Node*> vec = m[ch];
                Node* first = vec[0];
                m[ch].erase(m[ch].begin());

                first -> left -> right = first -> right;
                first -> right -> left = first -> left;
            }

            if(totalCount == 0) {
                int len = i - head->right->index + 1;
                if (len < minLen) {
                    minLen = len;
                    start = head->right->index;
                    end = i;
                }
            }

            Node * tmp = head -> right;
        }

        if(start == -1)
        {
            return "";
        }
        return s.substr(start,minLen);
    }
};