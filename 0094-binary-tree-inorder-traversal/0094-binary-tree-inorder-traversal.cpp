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
    void travesal(vector<int>& vec, TreeNode* cur) {
        if (cur == NULL) return;

        travesal(vec, cur->left);
        vec.push_back(cur->val);
        travesal(vec, cur->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        travesal(result, root);
        return result;
    }
};