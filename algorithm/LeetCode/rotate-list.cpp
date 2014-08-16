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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr) {
            return head;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        for (int i = 0; i < k; ++i) {
            if (fast->next == nullptr) {
                fast = head;
                k %= (i + 1);
                i = -1;
            } else {
                fast = fast->next;
            }
        }
        if (k == 0) {
            return head;
        }
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *newHead = slow->next;
        slow->next = nullptr;
        fast->next = head;
        return newHead;
    }
};
