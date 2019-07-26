/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p;
    struct ListNode *q;
    int i;
   
    p = head;
    q = head;
    
    for (i = 0; i < n; i++)
    {
        p = p->next;    
    }
    
    if (p == NULL)
    {
        head = head->next;
        return head;
    }
    
    for (;p->next != NULL; p = p->next)
    {
        q = q->next;
    }
    
    p = q->next;
    q->next = q->next->next;
    free(p);
   
     return head;
}

