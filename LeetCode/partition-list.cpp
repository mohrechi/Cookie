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
    ListNode *partition(ListNode *head, int x) {
        ListNode *low = nullptr;
        ListNode *high = nullptr;
        ListNode *lowHead = nullptr;
        ListNode *highHead = nullptr;
        ListNode *node = head;
        while (node != nullptr) {
            if (node->val < x) {
                if (low == nullptr) {
                    lowHead = node;
                } else {
                    low->next = node;
                }
                low = node;
            } else {
                if (high == nullptr) {
                    highHead = node;
                } else {
                    high->next = node;
                }
                high = node;
            }
            node = node->next;
        }
        if (low != nullptr) {
            low->next = nullptr;
        }
        if (high != nullptr) {
            high->next = nullptr;
        }
        if (lowHead == nullptr) {
            return highHead;
        }
        low->next = highHead;
        return lowHead;
    }
};
