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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        ListNode *tail;
        bool carry = false;
        while (t1 && t2) {
            t1->val += t2->val;
            if (carry)
                ++t1->val;
            if (t1->val >= 10) {
                t1->val -= 10;
                carry = true;
            } else
                carry = false;
            tail = t1;
            t1 = t1->next;
            t2 = t2->next;
        }
        if (!t1 && t2)
            tail->next = t2;
        while (carry && tail->next) {
            tail = tail->next;
            ++tail->val;
            if (tail->val >= 10) {
                tail->val -= 10;
                carry = true;
            } else
                carry = false;
        }
        if (carry) {
            ListNode *last = new ListNode(1);
            tail->next = last;
        }
        return l1;
    }
};
