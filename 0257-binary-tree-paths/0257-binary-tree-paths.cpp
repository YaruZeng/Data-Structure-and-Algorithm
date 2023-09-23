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
    void collectPath(vector<int>& path, vector<string>& result, TreeNode* cur) {
        path.push_back(cur->val); // collect the root
        if (cur->left == NULL && cur->right == NULL) { // collect path at end node
            string sPath;
            for (int i = 0; i < path.size() - 1; i++) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
            return;
        }

        if (cur->left) { // collect path through the left tree
            collectPath(path, result, cur->left);
            path.pop_back();
        }

        if (cur->right) { // collect path through the right tree
            collectPath(path, result, cur->right);
            path.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> result;
        collectPath(path, result, root);
        return result;
    }
};