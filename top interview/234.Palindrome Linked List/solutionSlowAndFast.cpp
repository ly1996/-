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
    bool isPalindrome(ListNode* head) {
        if(!head || !head -> next)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* before = NULL;
        
        while(fast && fast -> next)
        {
            fast = fast -> next -> next;
            
            ListNode* tmp = slow;
            
            slow = slow -> next;
            
            tmp -> next = before;
            
            before = tmp;
        }
        
        if(fast)
        {
            slow = slow -> next;
        }
        
        while(slow && before)
        {
            if(slow -> val != before -> val)
                return false;
            slow = slow -> next;
            before = before -> next;
        }
        
        return true;
    }
};