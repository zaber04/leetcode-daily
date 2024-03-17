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
int speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
    int dfs(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        if (!root->left) {
            return 1 + dfs(root->right);
        } else if (!root->right) {
            return 1 + dfs(root->left);
        }

        return 1 + min(dfs(root->left), dfs(root->right));
    }

public:
    int minDepth(TreeNode* root) {
        return dfs(root);
    }
};