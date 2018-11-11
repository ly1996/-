class Node{
public:
    int value;
    int index;
    int count;
    Node(int val , int i){
        value = val;
        index = i;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        stack<Node*> s;
        
        int maxRec = 0;
        
        for(int i = 0 ; i < len ; i ++)
        {
            Node * node = new Node(heights[i],i);
            
            int count = 1;
            while(!s.empty())
            {
                Node * top = s.top();
                
                if(top -> value >= heights[i])
                {
                    count = count + top -> count;
                    s.pop();
                    int rec = top -> value * (top -> count + i - (top -> index)- 1);
                    
                    if(rec > maxRec)
                    {
                        maxRec = rec;
                    }
                }
                else
                {
                    break;
                }
            }
            
            node -> count = count;
            
            // cout << node -> value << " " << node -> count <<  endl;
            s.push(node);
        }
        
        while(!s.empty())
        {
            Node * top = s.top();
            s.pop();
            
            int rec = top -> value * (top -> count + len - (top -> index) - 1);
            if(rec > maxRec)
            {
                maxRec = rec;
            }
        }
        
        return maxRec;
    }
};