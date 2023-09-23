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
    bool checkPath(TreeNode* cur, int count) {
        if (!cur->left && !cur->right && count == 0) return true;
        if (!cur->left && !cur->right) return false;

        if (cur->left) {
            count -= cur->left->val;
            if (checkPath(cur->left, count)) return true;
            count += cur->left->val;
        }

        if (cur->right) {
            count -= cur->right->val;
            if (checkPath(cur->right, count)) return true;
            count += cur->right->val;
        }

        return false;

    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;

        return checkPath(root, targetSum - root->val);
    }
};