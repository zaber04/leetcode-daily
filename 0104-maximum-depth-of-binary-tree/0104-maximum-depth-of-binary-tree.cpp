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
    int getDepth(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);

        return max(leftDepth, rightDepth) + 1;
    }
public:
    int maxDepth(TreeNode* root) {
        return getDepth(root);
    }
};