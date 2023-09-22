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
// Solution1: DFS, recursion

// class Solution {
// public:
//     void traversal(vector<int>& vec, TreeNode* cur) {
//         if (cur == NULL) return;
//         traversal(vec, cur->left);
//         traversal(vec, cur->right);
//         vec.push_back(cur->val);
//     }

//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> result;
//         traversal(result, root);
//         return result;
//     }
// };

// Solution2: BFS

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // postorder: left-right-mid -> mid-right-left
        stack<TreeNode*> st;
        vector<int> result;
        if (root != NULL) st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.push(NULL);
                if (node->right) st.push(node->right);
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