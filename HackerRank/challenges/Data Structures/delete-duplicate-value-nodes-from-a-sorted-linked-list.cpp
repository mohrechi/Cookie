Node* RemoveDuplicates(Node *head) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* removed = head;
    Node* node = head->next;
    while (node != nullptr) {
        if (removed->data != node->data) {
            removed->next = node;
            removed = node;
        }
        node = node->next;
    }
    removed->next = nullptr;
    return head;
}