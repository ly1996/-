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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0 ;
        
        ListNode* tmp = head;
        vector<ListNode*> nodeArray;
        while(tmp != NULL)
        {
            nodeArray.push_back(tmp);
            length ++;
            tmp = tmp -> next;
        }
        
        int index = length - n;
        
        if(index == 0)
        {
            return head -> next;
        }
        
        nodeArray[index - 1] -> next = nodeArray[index] -> next;
        
        return head;
    }
};