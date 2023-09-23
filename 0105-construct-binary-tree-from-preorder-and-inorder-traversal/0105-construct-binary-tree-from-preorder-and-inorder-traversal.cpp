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
    TreeNode* buildTreeHelper(vector<int>& preorder, int preorder_start, int preorder_end, vector<int>& inorder, int inorder_start, int inorder_end) {
        if (preorder_end - preorder_start == 0) return NULL;
        int rootValue = preorder[preorder_start];
        TreeNode* root = new TreeNode(rootValue);

        if (preorder_end - preorder_start == 1) return root;

        int delimiterIndex;
        for (delimiterIndex = inorder_start; delimiterIndex < inorder_end; delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) break;
        }

        root->left = buildTreeHelper(preorder, preorder_start + 1, preorder_start + 1 + delimiterIndex - inorder_start, inorder, inorder_start, delimiterIndex);
        root->right = buildTreeHelper(preorder, preorder_start + 1 + delimiterIndex - inorder_start, preorder_end, inorder, delimiterIndex + 1, inorder_end);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 && inorder.size() == 0) return NULL;
        return buildTreeHelper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};