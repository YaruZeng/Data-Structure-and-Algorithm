/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int getDepth(Node* cur) {
        if (cur == NULL) return 0;
        int depth = 0;
        for (int i = 0; i < cur->children.size(); i++) {
            depth = max(depth, getDepth(cur->children[i]));
        }
        return depth + 1;
    }

    int maxDepth(Node* root) {
        if (root == NULL) return 0;
        return getDepth(root);
    }
};