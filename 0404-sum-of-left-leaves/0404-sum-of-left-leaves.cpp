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
public:
    int sum = 0;
    void getSumOfLeftLeaves(TreeNode* cur) {
        if (cur == NULL) return;

        // postorder traversal
        if (cur->left) {
            getSumOfLeftLeaves(cur->left);
        }

        if (cur->right) {
            getSumOfLeftLeaves(cur->right);
        }

        if (cur->left && !cur->left->left && !cur->left->right) { // the left leaf node
            sum += cur->left->val;
        }
    }

    int sumOfLeftLeaves(TreeNode* root) {
        getSumOfLeftLeaves(root);
        return sum;
    }
};