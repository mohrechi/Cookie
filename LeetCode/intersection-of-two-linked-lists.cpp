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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        do {
            if (fast->next == NULL) {
                return NULL;
            }
            fast = fast->next;
            if (fast->next == NULL) {
                return NULL;
            }
            fast = fast->next;
            slow = slow->next;
        } while (slow != fast);
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        ListNode *tail = headA;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = headB;
        ListNode *intersection = detectCycle(headA);
        tail->next = NULL;
        return intersection;
    }
};
