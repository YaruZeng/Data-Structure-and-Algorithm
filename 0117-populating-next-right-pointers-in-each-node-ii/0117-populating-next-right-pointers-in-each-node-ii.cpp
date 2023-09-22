/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if (root != NULL) que.push(root);

        while (!que.empty()) {
            int size = que.size();
            Node* preNode;
            Node* curNode;
            for (int i = 0; i < size; i++) {
                curNode = que.front();
                que.pop();
                if (i == 0) {
                    preNode = curNode;
                } else {
                    preNode->next = curNode;
                    preNode = curNode;
                }
                if (curNode->left) que.push(curNode->left);
                if (curNode->right) que.push(curNode->right);
            }
            preNode->next = NULL;
        }
        return root;
    }
};