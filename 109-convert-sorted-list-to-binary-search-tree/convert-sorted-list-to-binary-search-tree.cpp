class Solution {
public:
    ListNode* find_middle(ListNode* head, ListNode* tail) {
        if (!head)
            return nullptr;
        ListNode *slow = head, *fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    TreeNode* helper(ListNode* head, ListNode* tail) {
        if (head == tail)
            return nullptr;
        ListNode* middle = find_middle(head, tail);
        TreeNode* root = new TreeNode(middle->val);
        root->left = helper(head, middle);
        root->right = helper(middle->next, tail);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return nullptr;
        return helper(head, nullptr);
    }
};