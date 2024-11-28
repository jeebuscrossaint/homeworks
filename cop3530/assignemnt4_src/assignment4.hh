#ifndef ASSIGNMENT4_HH
#define ASSIGNMENT4_HH

// queue section of the assignment

#include <cstddef>
#define MAX_SIZE 5

#include <array>
#include <iostream>

namespace queue { // queue namespace for assignment 4, part 1

        class Queue { // class going along for assignment 4 part 1
                public:
                        Queue(); // constructor
                        ~Queue(); // destructor

                        void enqueue(int val); // enqueue functionality
                        int dequeue(); // dequeue functionality
                        void display(); // display contents of the data vector.

                private:
                        int arr[MAX_SIZE];
                        int front;
                        int rear;
                        
        };
}

//======================================================================================================================

// traversing section of the assignment
#include <stack>
#include <memory>

namespace traversing {

        struct TreeNode {
                int value;
                TreeNode* left;
                TreeNode* right;

                TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
        };

        class Traversing {
                public:
                        Traversing(); // constructor
                        ~Traversing(); // destructor
                        void insert(int value); // add a node to a tree
                        void inOrderTraversal() const; // function to perform in order traversal using stack
                //private:
                        TreeNode* root; // root node of binary tree
                        void deleteTree(TreeNode* node); // helper function to delete a tree

        };
}

#endif // ASSIGNMENT4_HH