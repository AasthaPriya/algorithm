/*
question-link:https://leetcode.com/problems/remove-nth-node-from-end-of-list/
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Input: head = [1], n = 1
Output: []

Input: head = [1,2], n = 1
Output: [1]

Solution:Two pointers solution
*/

class Solution {
public:
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p=head, *q=head;
        
        for(; n--; q = q->next);
        
        if(q == NULL){
            q = p->next;
            delete(p);
            return q;
        }
        
        for(; q->next != NULL; p = p->next, q = q->next);
        
        q = p->next;        
        p->next = q->next;
        delete(q);
        
        return head;
    }
};