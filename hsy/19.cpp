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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *next = head;
        std::stack<ListNode*> list;
        while (next) {
            list.push(next);
            next = next->next;
        }
        
        ListNode *last;
        while (n--) {
            next = list.top();
            list.pop();
            last = next->next;
        }
        
        if (list.size()) {
            next = list.top();
            list.pop();
            next->next = last;
            return head;
        } else {
            return last;
        }
    }
};
