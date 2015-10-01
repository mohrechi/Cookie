Node* Reverse(Node *head, Node* prev = nullptr) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* next = head->next;
    head->next = prev;
    if (next == nullptr) {
        return head;
    }
    return Reverse(next, head);
}