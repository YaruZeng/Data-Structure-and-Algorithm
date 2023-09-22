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

// Solution 1: recursion
// class Solution {
// public:
//     void travesal(vector<int>& vec, TreeNode* cur) {
//         if (cur == NULL) return;

//         travesal(vec, cur->left);
//         vec.push_back(cur->val);
//         travesal(vec, cur->right);
//     }

//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> result;
//         travesal(result, root);
//         return result;
//     }
// };


// Solution2: iteration
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // inorder: left-mid-right -> right-mid-left
        stack<TreeNode*> st;
        vector<int> result;
        if (root != NULL) st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                if (node->right) st.push(node->right);
                st.push(node);
                st.push(NULL);
                if (node->left) st.push(node->left);
            } else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};