/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* firstApproach(TreeNode* root, TreeNode* p, TreeNode* q) {
        // expected parent must have value greater than p and less than q
        // All LEFT child nodes of LEFT subtree have values less or equal value
        // All RIGHT child nodes of RIGHT subtree have values greater value

        // assuming p < q
        // if value >p and >q, go left
        // if value <p and <q, go right
        // if value >p and <q --> return

        // input is a heap, so left is 2*r+1, right is 2*r+2

        TreeNode* current = root;

        while (true) {
            int curVal = current->val;

            if (curVal > p->val && curVal > q->val) {
                current = current->left;
            } else if (curVal < p->val && curVal < q->val) {
                current = current->right;
            } else {
                return current;
            }
        }
    }

    TreeNode* secondApproach(TreeNode* root, TreeNode* p, TreeNode* q) {
        return nullptr;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return firstApproach(root, p, q);
        // return secondApproach(root, p, q);
    }
};