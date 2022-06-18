#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node *connect(Node *root) {
        if (root == nullptr)
            return nullptr;

        queue<pair<Node *, int>> queue; //队列中一个节点为{指针，层号}

        pair<Node *, int> pre{root, 0};
        queue.push({root, 0});
        while (!queue.empty()) {
            auto cur = queue.front();
            queue.pop();

            if (pre.first != cur.first && pre.second == cur.second)
                pre.first->next = cur.first;
            pre = cur;

            if (cur.first->left != nullptr) {
                queue.push({cur.first->left, cur.second + 1});
            }
            if (cur.first->right != nullptr) {
                queue.push({cur.first->right, cur.second + 1});
            }
        }

        return root;
    }
};