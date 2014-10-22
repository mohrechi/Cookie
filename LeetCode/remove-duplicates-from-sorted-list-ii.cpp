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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *newHead = NULL;
        ListNode *prev = nullptr;
        ListNode *node = head;
        while (node != nullptr) {
            bool flag = true;
            ListNode *next = node->next;
            while (next != nullptr) {
                if (next->val != node->val) {
                    break;
                }
                flag = false;
                next = next->next;
            }
            if (flag) {
                if (prev == nullptr) {
                    newHead = node;
                } else {
                    prev->next = node;
                }
                prev = node;
            }
            node = next;
        }
        if (prev != nullptr) {
            prev->next = nullptr;
        }
        return newHead;
    }
};
