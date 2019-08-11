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
    int numComponents(ListNode* head, vector<int>& G) {
        ListNode *node = head;
        std::vector<int> poses;
        int i = 0;
        while (node) {
            for (auto e : G) {
                if (e == node->val) {
                    poses.push_back(i);
                }
            }
            node = node->next;
            ++i;
        }
        std::sort(poses.begin(), poses.end());
        
        int comp = 1;
        int last = poses[0];
        for (int i = 1; i < poses.size(); ++i) {
            if (last != (poses[i] - 1))
                ++comp;
            last = poses[i];
        }
        return comp;
    }
};
