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
    ListNode* sortList(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        ListNode* left = new ListNode(0);
        ListNode* right = new ListNode(0);
        
        int val = head -> val;
        ListNode* tail = head;
        ListNode* tmp = head -> next;
        ListNode* leftTmp = left;
        ListNode* rightTmp = right;
        while(tmp)
        {
            if(tmp -> val < val)
            {
                leftTmp -> next = tmp;
                leftTmp = tmp;
                // cout << tmp -> val << endl;
            }
            else if(tmp -> val == val)
            {
                tail -> next = tmp;
                tail = tmp;
            }
            else
            {
                rightTmp -> next = tmp;
                rightTmp = tmp;
                // cout << tmp -> val << endl;
            }
            
            tmp = tmp -> next;
        }
        leftTmp -> next = NULL;
        rightTmp -> next = NULL;
        left = sortList(left -> next);
        right = sortList(right -> next);
        
        tail -> next = right;
        if(left == NULL)
        {
            return head;
        }
        
        tail = left;
        while(tail -> next)
        {
            tail = tail -> next;
        }
        
        tail -> next = head;
        return left;
    }
};