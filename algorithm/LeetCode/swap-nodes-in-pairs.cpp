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
    ListNode *swapPairs(ListNode *head, int k = 2) {
        ListNode *prevHead = nullptr;
        ListNode *nextTail, *newHead = head;
        ListNode *node = head;
        while (true) {
            int i;
            if (node == nullptr) {
                break;
            }
            for (i = 1; i < k; ++i) {
                node = node->next;
                if (node == nullptr) {
                    break;
                }
            }
            if (i != k) {
                break;
            }
            nextTail = node->next;
            reverseList(head, nextTail);
            if (prevHead == nullptr) {
                newHead = node;
            } else {
                prevHead->next = node;
            }
            head->next = nextTail;
            prevHead = head;
            head = node = nextTail;
        }
        return newHead;
    }
private:
    void reverseList(ListNode *head, ListNode *tail) {
        ListNode *prev = head;
        ListNode *node = head->next;
        while (node != tail) {
            ListNode *next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
    }
};
