#include "assignment4.hh"
#include <stack>

using namespace traversing;

Traversing::Traversing() : root(nullptr) {};

Traversing::~Traversing() {
        deleteTree(root);
};

void Traversing::deleteTree(TreeNode* node) {
        if (node) {
                deleteTree(node->left);
                deleteTree(node->right);
                delete node;
        }
}

void Traversing::insert(int value) {
        if (!root) {
                root = new TreeNode(value);
                return;
        }

        // Perform a simple insertion
            TreeNode* current = root;
            while (true) {
                if (value < current->value) {
                    if (current->left) {
                        current = current->left;
                    } else {
                        current->left = new TreeNode(value);
                        break;
                    }
                } else {
                    if (current->right) {
                        current = current->right;
                    } else {
                        current->right = new TreeNode(value);
                        break;
                        }
                }
        }
}

void Traversing::inOrderTraversal() const {
        if(!root) {
                std::cout << "Tree is empty!" << std::endl;
                return;
        }

        std::stack<TreeNode*> nodeStack;
        TreeNode* current = root;

        while (current || !nodeStack.empty()) {
                // reach leftmost node of the current node
                while (current) {
                        nodeStack.push(current);
                        current = current->left;
                }

                // current must be null at this point
                current = nodeStack.top();
                nodeStack.pop();

                // print the value of the current node
                std::cout << current->value << " ";

                // move right on the subtree
                current = current->right;
        }

        std::cout << std::endl;
}

int main() {
        Traversing tree;

        // insert nodes
        tree.insert(50);
        tree.insert(30);
        tree.insert(70);
        tree.insert(20);
        tree.insert(40);
        tree.insert(60);
        tree.insert(80);

        // perform in order traversal
        std::cout << "In-Order Traversal: ";
        tree.inOrderTraversal();

        return 0;
}