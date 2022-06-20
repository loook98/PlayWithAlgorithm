#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};


class Solution {
public:
    Node *prev = nullptr;
    Node *head = nullptr;
    Node *treeToDoublyList(Node *root) {
        if (root == nullptr)
            return root;
        inorder(root);
        head->left = prev;
        prev->right = head;
        return head;
    }

    void inorder(Node *root) {
        if (root->left != nullptr)
            inorder(root->left);

        if (prev != nullptr)
            prev->right = root;
        else
            head = root;
        root->left = prev;
        prev = root;

        if (root->right != nullptr)
            inorder(root->right);
    }
};