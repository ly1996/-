class Node{
public:
    Node * left;
    Node * right;
    int val;
    int key;
};
class LRUCache {
public:
    int cap;
    int size = 0;
    Node * head = NULL;
    Node * tail = NULL;
    unordered_map<int, Node*> m;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    void moveNode(Node * tmp){
        if (tmp == head)
            return;
        tmp -> left -> right = tmp -> right;
        if(tmp == tail)
            tail = tmp -> left;
        else
            tmp -> right -> left = tmp -> left;
        tmp -> right = head;
        head -> left = tmp;
        head = tmp;
        
//         Node * current = head;
//         while(current)
//         {
//             cout << current -> key << " ";
//             current = current -> right;
//         }
        
//         cout << endl;
    }
    
    int get(int key) {
        // cout << "get key " << key << endl;
        if(m.find(key) == m.end())
        {
            return -1;
        }
        else
        {
            Node * tmp = m[key];
            moveNode(tmp);
            return tmp -> val;
        }
    }
    
    void put(int key, int value) {
        // cout << "put " << key << endl;
        
        if(m.find(key) != m.end())
        {
            Node * tmp = m[key];
            tmp -> val = value;
            moveNode(tmp);
            return;
        }
        
        Node * node = new Node();
        node -> key = key;
        node -> val = value;
        m[key] = node;
        
        if(head == NULL)
        {
            head = node;
            tail = node;
            size ++;
        }
        else
        {
            node -> right = head;
            head -> left = node;
            head = node;
            
            if(size == cap)
            {
                // cout << "rm tail " << tail -> val << endl;
                Node * tmp = tail;
                m.erase(tmp -> key); 
                tail = tail -> left;
                tail -> right = NULL;
                // delete tmp;
            }
            else
            {
                size ++;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */