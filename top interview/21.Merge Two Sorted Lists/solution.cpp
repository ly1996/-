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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *t1=l1, *t2=l2;
        ListNode *cur= new ListNode(0);
        ListNode *t3=cur;
        while(t1 && t2){
            if(t1->val<t2->val){
               // t3->val=t1->val;
                t3->next=t1;
                t1=t1->next;
                
            }
            else{
               // t3->val=t2->val;
                t3->next=t2;
                t2=t2->next;
                //t3=t3->next;
            }
            t3=t3->next;
        }
        
        while(t1){
            t3->next=t1;
            t1=t1->next;
            t3=t3->next;
        }
        while(t2){
             t3->next=t2;
             t2=t2->next;
             t3=t3->next;
        }
        ListNode *res=cur->next;
        delete cur;
        return res;
    }
};