class Node{
public:
    Node * left;
    Node * right;
    int val;
    Node(int v){
        val = v;
        left = NULL;
        right = NULL;
    }
};

class MinStack {
public:
    Node * head;
    stack<Node*> s;
    /** initialize your data structure here. */
    MinStack() {
        head = new Node(0);
    }
    
    void push(int x) {
        Node * node = new Node(x);
        s.push(node);
        Node * current = head;
        while(current -> right != NULL)
        {
            if(x > current -> right -> val)
            {
                current = current -> right;
            }
            else
            {
                break;
            }
        }
        
        node -> right = current -> right;
        node -> left = current;
        
        if(current -> right != NULL)
            current -> right -> left = node;
        current -> right = node;
        
        // current = head -> right;
        // while(current != NULL)
        // {
        //     cout << (current -> val) << " ";
        //     current = current -> right;
        // }
        // cout << endl;
    }
    
    void pop() {
        Node * node = s.top();
        s.pop();
        node -> left -> right = node -> right;
        // cout << node -> left -> val << endl;
        if(node -> right != NULL)
        {
            node -> right -> left = node -> left;
        }
        
        Node * current = head -> right;
        while(current != NULL)
        {
            // cout << (current -> val) << " ";
            current = current -> right;
        }
        cout << endl;
    }
    
    int top() {
        return s.top() -> val;
    }
    
    int getMin() {
        return head -> right -> val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */