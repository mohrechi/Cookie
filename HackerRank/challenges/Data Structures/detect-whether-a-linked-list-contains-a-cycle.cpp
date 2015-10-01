int HasCycle(Node* head) {
    if (head == nullptr) {
        return 0;
    }
    Node* slow = head;
    Node* fast = head;
    while (true) {
        slow = slow->next;
        fast = fast->next;
        if (fast != nullptr) {
            fast = fast->next;
        }
        if (fast == nullptr) {
            return 0;
        }
        if (slow == fast) {
            return 1;
        }
    }
    return 0;
}