#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<pair<Node *, int>> bfsQ;

        bfsQ.push({root, 0});
        int lastLevel = 0;
        vector<int> curNodes;
        while (!bfsQ.empty()) {
            auto pair = bfsQ.front();
            bfsQ.pop();
            Node *node = pair.first;
            int level = pair.second;

            if (level != lastLevel) {
                res.push_back(curNodes);
                curNodes.clear();
                lastLevel = level;
            }

            curNodes.push_back(node->val);
            for (auto child : node->children) {
                bfsQ.push({child, level + 1});
            }
        }
        res.push_back(curNodes);

        return res;
    }
};