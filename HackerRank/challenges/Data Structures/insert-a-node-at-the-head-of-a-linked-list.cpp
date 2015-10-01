Node* Insert(Node *head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    return newNode;
}