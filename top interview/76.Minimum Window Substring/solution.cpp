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
        string result = "";
        int start = 0;
        int end = 0;
        
        vector<int> tchars(256,0);
        vector<int> schars(256,0);
        
        int types_of_char = 0;
        for(char ch : t)
        {
            if(tchars[ch] == 0)
            {
                types_of_char ++;
            }
            tchars[ch] ++;
        }
        
        int types_of_char_now = 0;
        
        while(true)
        {
            while(true)
            {
                if(end >= s.size())
                {
                    return result;
                }
                
                char ch = s[end];
                if(tchars[ch] > 0)
                {
                    schars[ch] ++;
                    
                    if(schars[ch] == tchars[ch])
                    {
                        types_of_char_now ++;
                    }
                    
                    if(types_of_char_now == types_of_char)
                    {
                        end ++;
                        break;
                    }
                }
                end ++;
            }
            
            while(true)
            {
                char ch = s[start];
                if(tchars[ch] > 0)
                {
                    schars[ch] --;
                    
                    if(schars[ch] < tchars[ch])
                    {
                        types_of_char_now --;
                        if(result == "" || result.size() > end - start)
                        {
                            result = s.substr(start, end - start);
                        }
                        
                        start ++;
                        break;
                    }
                }
                
                start ++;
            }
        }
        
        return result;
    }
};