/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    deque<char> tail = {'|'};

    void traverse(TreeNode* node, deque<char>& head) {
        if (node == nullptr) {
            return;
        }

        head.push_front(node->val + 'a');

        if (node->left == nullptr && node->right == nullptr) {
            if (head < tail) {
                tail = head;
            }
        }

        traverse(node->left, head);
        traverse(node->right, head);
        head.pop_front();
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        deque<char> head = {};

        traverse(root, head);
        return string(tail.begin(), tail.end());
    }
};