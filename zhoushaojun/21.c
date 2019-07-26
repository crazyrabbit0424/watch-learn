/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode l3;
    struct ListNode *p, *q, *w;
    l3.next = NULL;
    p = &l3;
    q = l1;
    w = l2;
    
    while ((NULL != q) && (NULL != w))
    {
        if (q->val < w->val)
        {
            p->next = q;
            q = q->next;
            p = p->next;
        }
        else
        {
            p->next = w;
            w = w->next;
            p = p->next;
        }
    }
    
    if (NULL != q)
    {
        p->next = q;
    }
    
    if (NULL != w)
    {
        p->next = w;
    }
    
    return l3.next;
}
