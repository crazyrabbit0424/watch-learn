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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2)
            return (!l1 ? l2 : l1);
        ListNode *res = l1->val >= l2->val ? l2 : l1;
        ListNode *next = res;
        ListNode *n1 = res == l1 ? l1->next : l1;
        ListNode *n2 = res == l2 ? l2->next : l2;
        while (n1 && n2) {
            if (n1->val > n2->val) {
                next->next = n2;
                n2 = n2->next;
            } else {
                next->next = n1;
                n1 = n1->next;
            }
            next = next->next;
        }
        next->next = n1 ? n1 : n2;
        
        return res;
    }
};
