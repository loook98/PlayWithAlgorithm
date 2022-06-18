#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;

        queue<pair<Node *, int>> queue;
        queue.push(make_pair(root, 0));
        while (!queue.empty()){
            auto pair = queue.front();
            queue.pop();
            Node *node = pair.first;
            int level = pair.second;

            if (node->left)
                queue.push(make_pair(node->left, level+1));
            if (node->right)
                queue.push(make_pair(node->right, level+1));

            if (!queue.empty()){
                auto nextPair = queue.front();
                if (level == nextPair.second)
                    node->next = nextPair.first;
            }
        }

        return root;
    }
};