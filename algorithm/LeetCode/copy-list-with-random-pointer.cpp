/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr) {
            return head;
        }
        RandomListNode *node = head;
        while (node != nullptr) {
            RandomListNode *newNode = new RandomListNode(node->label);
            newNode->next = node->next;
            node->next = newNode;
            node = newNode->next;
        }
        node = head;
        while (node != nullptr) {
            if (node->random != nullptr) {
                node->next->random = node->random->next;
            }
            node = node->next->next;
        }
        node = head;
        RandomListNode *newHead = head->next;
        while (node != nullptr) {
            RandomListNode *newNode = node->next;
            node->next = newNode->next;
            if (node->next != nullptr) {
                newNode->next = node->next->next;
            }
            node = node->next;
        }
        return newHead;
    }
};
