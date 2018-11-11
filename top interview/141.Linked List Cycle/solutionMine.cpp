/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
        {
            return false;
        }
        
        ListNode * tail = new ListNode(0);
        
        ListNode * current = head;
        
        while(current != NULL)
        {
            ListNode * tmp = current -> next;
            
            if(tmp == tail)
            {
                return true;
            }
            
            current -> next = tail;
            current = tmp;
        }
        
        return false;
    }
};