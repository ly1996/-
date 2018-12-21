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
        
        map<RandomListNode *,RandomListNode *> m;
        RandomListNode * beforeNode = before;
        RandomListNode * currentNode = head;
        while(currentNode)
        {
            RandomListNode * tmp = new RandomListNode(currentNode -> label);
            m[currentNode] = tmp;
            beforeNode -> next = tmp;
            beforeNode = tmp;
            currentNode = currentNode -> next;
        }
        
        currentNode = head;
        RandomListNode * tmp = before -> next;
        while(currentNode)
        {
            tmp -> random = m[currentNode -> random];
            currentNode = currentNode -> next;
            tmp = tmp -> next;
        }
        
        return before -> next;
    }
};