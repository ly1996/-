/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode * before = new RandomListNode(0);
        if(!head)
            return NULL;
        
        RandomListNode * currentNode = head;
        while(currentNode)
        {
            RandomListNode * newNode = new RandomListNode(currentNode -> label);
            newNode -> next = currentNode -> next;
            currentNode -> next = newNode;
            currentNode = newNode -> next;
        }
        
        currentNode = head;
        while(currentNode)
        {
            if(currentNode -> random)
                currentNode -> next -> random = currentNode -> random -> next;
            currentNode = currentNode -> next -> next;
        }
        
        RandomListNode * returnList = head -> next;
        RandomListNode * tmp = head -> next;
        currentNode = head;
        while(currentNode)
        {
            currentNode -> next = currentNode -> next -> next;
            if(tmp -> next)
            {
                tmp -> next = tmp -> next -> next;
            }
            
            currentNode = currentNode -> next;
            tmp = tmp -> next;
        }
        
        return returnList;
    }
};