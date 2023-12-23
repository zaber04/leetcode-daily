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
    void inOrderDfs(TreeNode* root, vector<int> &arr) {
        if (root != NULL) {
            inOrderDfs(root->left, arr);
            arr.push_back(root->val);
            inOrderDfs(root->right, arr);
        }
    }

    vector<int> firstApproach(TreeNode* root) {
        // left -> root -> right
        vector<int> arr;
        inOrderDfs(root, arr);
        return arr;
    }

    vector<int> secondApproach(TreeNode* root) {
        vector<int> arr;
        stack<TreeNode*> stk;

        TreeNode *temp = root;

        while (temp != NULL || !stk.empty()) {
            while (temp != NULL) {
                stk.push(temp);
                temp = temp->left;
            }

            temp = stk.top();
            stk.pop();
            arr.push_back(temp->val);
            
            temp = temp->right;
        }

        return arr;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // return firstApproach(root);
        return secondApproach(root);
    }
};