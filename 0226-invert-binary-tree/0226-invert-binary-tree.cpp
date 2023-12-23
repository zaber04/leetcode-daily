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
void mirror(TreeNode* nod) {
    if (!nod) {
        return;
    }

    // do the subtrees
    mirror(nod->left);
    mirror(nod->right);
    
    TreeNode* temp;
    // swap left and right leaf node
    temp = nod->right;
    nod->right = nod->left;
    nod->left = temp;
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        mirror(root);
        return root;
    }
};