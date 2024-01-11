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
    int maxMinusMin(TreeNode* node, int tempMax, int tempMin) {
        if (node == NULL) {
            return tempMax - tempMin;
        }

        tempMax = max(tempMax, node->val);
        tempMin = min(tempMin, node->val);

        int leftTreeMax = maxMinusMin(node->left, tempMax, tempMin);
        int rightTreeMax = maxMinusMin(node->right, tempMax, tempMin);

        return max(leftTreeMax, rightTreeMax);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
         if (root == NULL) {
            return 0;
        }
        return maxMinusMin(root, root->val, root->val);
    }
};