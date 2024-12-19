//
// Created by Andrey on 19.12.2024.
//

#ifndef NODE_H
#define NODE_H
#include <vector>

using namespace std;


class Tree {
public:
    struct Node {
        int key;
        Node *left;
        Node *right;
    };

    static Node* newNode(int key) {
        Node* temp = new Node;
        temp->key = key;
        temp->left = temp->right = nullptr;
        return temp;
    }

    Node* insert(Node* root, int key) {
        if (root == nullptr) {
            return newNode(key);
        }

        if (key < root->key) {
            root->left = insert(root->left, key);
        } else {
            root->right = insert(root->right, key);
        }

        return root;
    }

    void inorderTraversal(Node* root, vector<int>& sortedKeys) {
        if (root != nullptr) {
            inorderTraversal(root->left, sortedKeys);
            sortedKeys.push_back(root->key);
            inorderTraversal(root->right, sortedKeys);
        }
    }

    vector<int> sort(Node* root) {
        vector<int> sortedKeys;
        inorderTraversal(root, sortedKeys);
        return sortedKeys;
    }
};



#endif //NODE_H
