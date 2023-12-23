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
    void preOrderTraversal(TreeNode *node, string &str) {
        if (node == nullptr) {
            return;
        }

        str += to_string(node->val);

        // child exits or not --> we add () --> for right child
        if (!(node->left == nullptr && node->right == nullptr)) {
            str += "(";
            preOrderTraversal(node->left, str);
            str += ")";
        }

        // right child exits?
        if (node->right != nullptr) {
            str += "(";
            preOrderTraversal(node->right, str);
            str += ")";
        }        
    }

    string firstApproach(TreeNode* root) {
        // add () when there is an empty node on left and right node exists.
        // if the root has just a right child (left child is null) you have to 
        // add a pair of empty parenthesis to clearly show left child in null but if
        // root has just left child (right child is null) you don't have to add a pair
        // of empty parenthesis (cause we can understand that it doesn't have right 
        // child) and for the third case if the root have no child you gotta stop there .
        string str = "";
        preOrderTraversal(root, str);

        return str;
    }
public:
    string tree2str(TreeNode* root) {
        return firstApproach(root);
    }
};