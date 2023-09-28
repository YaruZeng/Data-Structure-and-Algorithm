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

    vector<int> robTree(TreeNode* node) {
        if (node == NULL) return {0, 0};

        vector<int> left = robTree(node->left);
        vector<int> right = robTree(node->right);

        int dp0 = max(left[0], left[1]) + max(right[0], right[1]); // not steal the current node
        int dp1 = left[0] + right[0] + node->val; // steal the current node

        return {dp0, dp1};
    }

    int rob(TreeNode* root) {
        if (root == NULL) return 0;

        vector<int> result = robTree(root);

        return max(result[0], result[1]);
    }
};