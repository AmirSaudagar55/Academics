#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertHelper(root, value);
        cout << "Value " << value << " inserted." << endl;
        printTree();
    }

    Node* insertHelper(Node* node, int value) {
        if (node == nullptr) {
            node = new Node(value);
            return node;
        }

        if (value < node->data) {
            node->left = insertHelper(node->left, value);
        } else if (value > node->data) {
            node->right = insertHelper(node->right, value);
        }

        return node;
    }

    void mirror() {
        mirrorHelper(root);
        cout << "Mirror image created." << endl;
        printTree();
    }

    void mirrorHelper(Node* node) {
        if (node == nullptr) {
            return;
        }

        mirrorHelper(node->left);
        mirrorHelper(node->right);

        // Swap the left and right child nodes
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }

    void printLeafNodes() {
        printLeafNodesHelper(root);
        cout << endl;
    }

    void printLeafNodesHelper(Node* node) {
        if (node == nullptr) {
            return;
        }

        if (node->left == nullptr && node->right == nullptr) {
            cout << node->data << " ";
        }

        printLeafNodesHelper(node->left);
        printLeafNodesHelper(node->right);
    }

    int height() {
        return heightHelper(root);
    }

    int heightHelper(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = heightHelper(node->left);
        int rightHeight = heightHelper(node->right);

        return max(leftHeight, rightHeight) + 1;
    }

    void preorder() {
        preorderHelper(root);
        cout << endl;
    }

    void preorderHelper(Node* node) {
        if (node == nullptr) {
            return;
        }

        cout << node->data << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }

    int minimum() {
        Node* current = root;
        while (current->left != nullptr) {
            current = current->left;
        }

        return current->data;
    }

    bool search(int value) {
        return searchHelper(root, value);
    }

    bool searchHelper(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (node->data == value) {
            return true;
        }

        if (value < node->data) {
            return searchHelper(node->left, value);
        } else {
            return searchHelper(node->right, value);
        }
    }

    void printTree() {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }

        cout << "Tree:" << endl;
        printTreeHelper(root);
        cout << endl;
    }

    void printTreeHelper(Node* node) {
        if (node == nullptr) {
            return;
        }

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                Node* curr = q.front();
                q.pop();

                cout << curr->data << " ";

                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }

            cout << endl;
        }
    }
};

int main() {
    BinaryTree tree;
    int option, value;

    do {
        cout << "\n-------------------------";
        cout << "\nBinary Search Tree Program";
        cout << "\n-------------------------";
        cout << "\n1. Insert";
        cout << "\n2. Mirror";
        cout << "\n3. Print Leaf Nodes";
        cout << "\n4. Height";
        cout << "\n5. Preorder Traversal";
        cout << "\n6. Minimum Value";
        cout << "\n7. Search";
        cout << "\n8. Exit";
        cout << "\nEnter your option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                tree.mirror();
                break;
            case 3:
                cout << "Leaf Nodes: ";
                tree.printLeafNodes();
                break;
            case 4:
                cout << "Height of the tree: " << tree.height() << endl;
                break;
            case 5:
                cout << "Preorder Traversal: ";
                tree.preorder();
                break;
            case 6:
                cout << "Minimum value: " << tree.minimum() << endl;
                break;
            case 7:
                cout << "Enter the value to search: ";
                cin >> value;
                if (tree.search(value)) {
                    cout << "Value found in the tree." << endl;
                } else {
                    cout << "Value not found in the tree." << endl;
                }
                break;
            case 8:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    } while (option != 8);

    return 0;
}
