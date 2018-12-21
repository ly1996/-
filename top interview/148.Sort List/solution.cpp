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
        if(!head || !head->next) return head;
        
        //break into two sublists
        ListNode* slow=head;
        ListNode* fast=head->next->next; 
        while(slow && fast){
            //cout<<slow->val<<" "<<fast->val<<"\n";
            slow=slow->next;
            if(fast->next) fast=fast->next->next;
            else break;
        }
        ListNode* newhead=slow->next;
        ListNode* cur=newhead;
        slow->next=nullptr;
        
        //sort two sublists
        newhead=sortList(newhead);
        head=sortList(head);
        
        //then merge two sorted lists
        return mergeTwoLists(head, newhead);
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val<=l2->val) {
            l1->next=mergeTwoLists(l1->next, l2);
            return l1;
        }
        if(l2->val<l1->val){
            l2->next=mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
    
};