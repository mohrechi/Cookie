Node* Insert(Node *head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    if (head == nullptr) {
        return newNode;
    }
    Node* node = head;
    while (node->next != nullptr) {
        node = node->next;
    }
    node->next = newNode;
    return head;
}
