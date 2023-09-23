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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL; // cannot find key

        if (root->val == key) { // find key
            if (root->left == NULL && root->right == NULL) return NULL;
            else if (root->left == NULL) {
                TreeNode* retNode = root->right;
                delete root;
                return retNode;
            } else if (root->right == NULL) {
                TreeNode* retNode = root->left;
                delete root;
                return retNode;
            } else {
                TreeNode* cur = root->right;
                while (cur->left != NULL) {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* retNode = root->right;
                delete root;
                return retNode;
            }
        }

        if (key < root->val) root->left = deleteNode(root->left, key);
        if (key > root->val) root->right = deleteNode(root->right, key);

        return root;
    }
};