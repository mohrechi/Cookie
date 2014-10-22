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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *prevM = nullptr;
        ListNode *nodeM = head;
        for (int i = 1; i < m; ++i) {
            prevM = nodeM;
            nodeM = nodeM->next;
        }
        ListNode *nodeN = head;
        for (int i = 1; i < n; ++i) {
            nodeN = nodeN->next;
        }
        ListNode *nextN = nodeN->next;
        reverseList(nodeM, nextN);
        if (prevM == nullptr) {
            head = nodeN;
        } else {
            prevM->next = nodeN;
        }
        nodeM->next = nextN;
        return head;
    }
private:
    void reverseList(ListNode *head, ListNode *tail) {
        if (head == nullptr) {
            return;
        }
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
