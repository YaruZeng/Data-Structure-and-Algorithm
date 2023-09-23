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
    TreeNode* buildTreeHelper(vector<int>& inorder, int inorder_start, int inorder_end, vector<int>& postorder, int postorder_start, int postorder_end) {
        if (postorder_end - postorder_start == 0) return NULL; // no node inside postorder

        int rootValue = postorder[postorder_end - 1]; // the last node in postorder is the root
        TreeNode* root = new TreeNode(rootValue);

        if (postorder_end - postorder_start == 1) return root; // only one node in the tree

        int delimiterIndex;
        for (delimiterIndex = inorder_start; delimiterIndex < inorder_end; delimiterIndex++) { // find the root index in inorder
            if (inorder[delimiterIndex] == rootValue) break;
        }

        // use the root to split left tree and right tree
        root->left = buildTreeHelper(inorder, inorder_start, delimiterIndex, postorder, postorder_start, postorder_start + delimiterIndex - inorder_start);
        root->right = buildTreeHelper(inorder, delimiterIndex + 1, inorder_end, postorder, postorder_start + delimiterIndex - inorder_start, postorder_end - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 && postorder.size() == 0) return NULL;
        return buildTreeHelper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};