/*
question link:https://leetcode.com/problems/merge-k-sorted-lists/
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Solution: Using Priority Queue 
*/

class Solution
{
    public:
    struct compare
    {
        bool operator()(ListNode* node1, ListNode* node2)
        {
            return node1->val>=node2->val;
        }        
    };
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i])
                pq.push(lists[i]);            
        }
        ListNode *head=NULL,*temp,*top;
        while(!pq.empty())
        {
            top=pq.top();
            ListNode* newnode=new ListNode(top->val);
            if(head==NULL)
            {
                head=newnode;
                temp=head;
            }
            else
            {
                temp->next=newnode;
                temp=temp->next;
            }
            top=top->next;
            pq.pop();
            if(top)
                pq.push(top);
        }
        return head;
    }
};