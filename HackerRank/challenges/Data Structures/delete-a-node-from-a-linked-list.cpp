Node* Delete(Node *head, int position) {
    if (position == 0) {
        return head->next;
    }
    Node *node = head;
    for (int i = 1; i < position; ++i) {
        node = node->next;
    }
    node->next = node->next->next;
    return head;
}