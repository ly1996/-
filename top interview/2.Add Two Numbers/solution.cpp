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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	//把l1作为返回的节点
        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        
        ListNode* before = NULL;
        ListNode* current = l1;
        
        while(tmp1 != NULL && tmp2 != NULL)
        {
            int re = tmp1 -> val + tmp2 -> val;
            
            if(re < 10)
            {
                current -> val = re;
            }
            else
            {
                current -> val = re - 10;
                if(current -> next != NULL)
                {
                    current -> next -> val += 1;
                }
                else
                {
                    current -> next = new ListNode(1);
                }
            }
            
            tmp1 = tmp1 -> next;
            tmp2 = tmp2 -> next;
            before = current;
            current = current -> next;
        }
        
        if(tmp1 != NULL)
        {
		//考虑进位
            while(tmp1 -> val >= 10)
            {
                tmp1 -> val -= 10;
                if(tmp1 -> next != NULL)
                {
                    tmp1 -> next -> val += 1;
                }
                else
                {
                    tmp1 -> next = new ListNode(1);
                }
                tmp1 = tmp1 -> next;
            }
        }
        else if(tmp2 != NULL)
        {
            before -> next = tmp2;
        }
        
        return l1;
    }
};