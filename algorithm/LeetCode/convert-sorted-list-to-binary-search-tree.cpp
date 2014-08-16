/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        return build(head, nullptr);
    }
private:
    TreeNode *build(ListNode *head, ListNode *tail) {
        if (head == nullptr || head == tail) {
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != tail) {
            fast = fast->next;
            if (fast->next == tail) {
                break;
            }
            fast = fast->next;
            slow = slow->next;
        }
        TreeNode *tree = new TreeNode(slow->val);
        tree->left = build(head, slow);
        tree->right = build(slow->next, tail);
    }
};
