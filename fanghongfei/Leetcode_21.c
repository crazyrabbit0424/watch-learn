/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

    struct ListNode *tmp;
    struct ListNode *l3;

    if (l1 == NULL && l2 == NULL)
    {
        return NULL; 
    }
    
    if (l1 == NULL)
    {
        return l2;
    }
    
    if (l2 == NULL)
    {
        return l1;
    }

    if (l1->val <= l2->val)
    {
        l3 = l1;
    }
    else
    {
        l3 = l2;
    }
    
    tmp = l3;
    if (l1->val <= l2->val)
    {
        l1 = l1->next;
    }
    else
    {
        l2 = l2->next;
    }
    
    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            l3->next = l1;
		    l3 = l1;
            l1 = l1->next;
        }
        else
        {
            l3->next = l2;        
            l3 = l2;
            l2 = l2->next;
        }
    }
    
    l3->next = l1 ? l1 : l2;
    
    return tmp;

}
