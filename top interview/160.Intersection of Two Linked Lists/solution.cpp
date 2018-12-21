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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        
        ListNode * cur = headA;
        while(cur != NULL)
        {
            lenA ++;
            cur = cur -> next;
        }
        
        
        cur = headB;
        while(cur != NULL)
        {
            lenB ++;
            cur = cur -> next;
        }
        
        while(lenA > lenB)
        {
            headA = headA -> next;
            lenA --;
        }
        
        while(lenB > lenA)
        {
            headB = headB -> next;
            lenB --;
        }
        
        while(headA != NULL)
        {
            if(headA == headB)
            {
                return headA;
            }
            
            headA = headA -> next;
            headB = headB -> next;
        }
        
        return NULL;
    }
};