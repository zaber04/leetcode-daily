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
    int maxDistance = 0;

    int traverse(TreeNode* root, int start) {
        int depth = 0;

        if (root == nullptr) {
            return depth;
        }

        int leftDepth = traverse(root->left, start);
        int rightDepth = traverse(root->right, start);

        if (root->val == start) {
            maxDistance = max(leftDepth, rightDepth);
            depth = -1;
        } else  if (leftDepth >= 0 && rightDepth >= 0) {
            depth = max(leftDepth, rightDepth) + 1;
        } else {
            int distance = abs(leftDepth) + abs(rightDepth);
            maxDistance = max(maxDistance, distance);
            depth = min(leftDepth, rightDepth) - 1;
        }

        return depth;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        // If root = null return 0.
        // Make a recursive call with root.right and save as rightDepth.
        // Make a recursive call with root.left and save as leftDepth.
        // Return max(rightDepth, leftDepth) + 1.
        
        traverse(root, start);
        return maxDistance;
    }
};