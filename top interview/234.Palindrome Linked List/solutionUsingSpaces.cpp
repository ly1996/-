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
        int len = 0;
        if(!head || !head -> next)
            return true;
        ListNode* tmp = head;
        while(tmp)
        {
            len ++;
            tmp = tmp -> next;
        }
        
        int start = (len + 1)/2 + 1;
        
        int count = 1;
        tmp = head;
        while(count != start)
        {
            count ++;
            tmp = tmp -> next;
        }
        
        ListNode* nextNode = tmp -> next;
        tmp -> next = NULL;
        
        while(nextNode)
        {
            ListNode* current = nextNode -> next;
            nextNode -> next = tmp;
            tmp = nextNode;
            nextNode = current;
        }
        
        while(tmp && head)
        {
            if(tmp -> val != head -> val)
                return false;
            tmp = tmp -> next;
            head = head -> next;
        }
        
        return true;
    }
};