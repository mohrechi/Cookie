void ReversePrint(Node *head) {
    if (head == nullptr) {
        return;
    } 
    ReversePrint(head->next);
    cout << head->data << endl;
}