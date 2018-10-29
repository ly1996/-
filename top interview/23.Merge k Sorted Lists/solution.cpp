/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNodeCompare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* nodeReturn = new ListNode(0);
        ListNode* cur = nodeReturn;
        priority_queue<ListNode*,vector<ListNode*>,ListNodeCompare> q;
        
        for(int i = 0 ; i < lists.size() ; i ++)
        {
            if(lists[i] != NULL)
            {
                q.push(lists[i]);
            }
        }
        
        while(!q.empty())
        {
            ListNode* node= q.top();
            cur -> next = node;
            cur = cur -> next;
            q.pop();
            if(node -> next != NULL)
            {
                q.push(node -> next);
            }
        }
        
        return nodeReturn -> next;
    }
};