#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    char value;
    TreeNode* left;
    TreeNode* right;
};

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

TreeNode* createExpressionTree(string prefixExpression) {
    stack<TreeNode*> stk;

    for (int i = prefixExpression.size() - 1; i >= 0; i--) {
        char c = prefixExpression[i];
        TreeNode* node = new TreeNode{c, nullptr, nullptr};

        if (isOperator(c)) {
            node->left = stk.top();
            stk.pop();
            node->right = stk.top();
            stk.pop();
        }

        stk.push(node);
    }

    return stk.top();
}

void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->value << " ";
}

void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    string prefixExpression = "+--a*bc/def";
    TreeNode* root = createExpressionTree(prefixExpression);

    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;

    deleteTree(root);

    return 0;
}
