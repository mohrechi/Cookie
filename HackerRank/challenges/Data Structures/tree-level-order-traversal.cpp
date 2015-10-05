#include <queue>
using namespace std;

void LevelOrder(node* root) {
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        auto& node = q.front();
        q.pop();
        if (node == nullptr) {
            continue;
        }
        cout << node->data << " ";
        q.push(node->left);
        q.push(node->right);
    }
}