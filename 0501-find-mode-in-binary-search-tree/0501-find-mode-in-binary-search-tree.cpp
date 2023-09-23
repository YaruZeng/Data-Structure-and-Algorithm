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
    vector<int> result;
    TreeNode* preNode = NULL;
    int maxCount = 0;
    int count = 0;

    void findModeHelper(TreeNode* node) {
        if (node == NULL) return;

        findModeHelper(node->left);
        if (preNode == NULL) count = 1;
        else if (preNode->val == node->val) count++;
        else count = 1;
        preNode = node;

        if (count == maxCount) result.push_back(node->val);
        if (count > maxCount) {
            result.clear();
            maxCount = count;
            result.push_back(node->val);
        }

        findModeHelper(node->right);
    }

    vector<int> findMode(TreeNode* root) {
        if (root == NULL) return result;
        findModeHelper(root);
        return result;
    }
};