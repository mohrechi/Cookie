int FindMergeNode(Node *headA, Node *headB) {
    Node* node = headA;
    while (node->next != nullptr) {
        node = node->next;
    }
    node->next = headB;
    Node* slow = headA;
    Node* fast = headA;
    while (true) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = headA;
            break;
        }
    }
    while (true) {
        slow = slow->next;
        fast = fast->next;
        if (slow == fast) {
            break;
        }
    }
    return slow->data;
}