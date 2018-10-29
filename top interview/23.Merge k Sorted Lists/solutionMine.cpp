/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 bool comp(ListNode * n1 , ListNode * n2){
        if(n1 == NULL)
        {
            return false;
        }
        if(n2 == NULL)
        {
            return true;
        }
        return n1-> val < n2 -> val;
}
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> curList;
        for(int i = 0 ; i < lists.size() ; i ++)
        {
            if(lists[i] != NULL) curList.push_back(lists[i]);
        }
        
        ListNode * first = NULL;
        ListNode * cur = first;
        while(!isAllNull(curList))
        {
            sort(curList.begin() , curList.end() , comp);
            if(first == NULL)
            {
                first = new ListNode(curList[0] -> val);
                cur = first;
            }
            else
            {
                ListNode * tmp = new ListNode(curList[0] -> val);
                cur -> next = tmp;
                cur = tmp;
            }
            curList[0] = curList[0] -> next;
            while(curList[0] == NULL)
            {
                curList.erase(curList.begin());
                if(curList.size() == 0)
                break;
                ListNode * tmp = new ListNode(curList[0] -> val);
                curList[0] = curList[0] -> next;
                cur -> next = tmp;
                cur = tmp;
            }
        }
        
        return first;
    }
    
    bool isAllNull(vector<ListNode*> & curList){
        bool isAllNull = true;
        
        for(int i = 0 ; i < curList.size() ; i++)
        {
            if(curList[i] != NULL)
            {
                isAllNull = false;
                break;
            }
            else continue;
        }
        return isAllNull;
    }
};