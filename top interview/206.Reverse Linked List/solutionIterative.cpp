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
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return NULL;
        ListNode* before = head;
        ListNode* current = head -> next;
        before -> next = NULL;
        while(current)
        {
            // cout << current -> val << endl;
            ListNode* tmp = current -> next;
            current -> next = before;
            
            before = current;
            current = tmp;
        }
        
        return before;
    }
};