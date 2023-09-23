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
    int isBalancedCheck(TreeNode* cur) {
        if (cur == NULL) return 0; 

        int left = isBalancedCheck(cur->left);
        if (left == -1) return -1;
        int right = isBalancedCheck(cur->right);
        if (right == -1) return -1;

        if (abs(right - left) > 1) return -1;
        else {
            return 1 + max(right, left);
        }
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        return isBalancedCheck(root) == -1 ? false : true;
    }
};