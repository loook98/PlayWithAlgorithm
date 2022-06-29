#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isCompleteTree(TreeNode *root) {
        bool terminated = false;

        queue<TreeNode *> bfsQueue;
        bfsQueue.push(root);

        while (!bfsQueue.empty()){
            TreeNode *node = bfsQueue.front();
            bfsQueue.pop();

            if (node == nullptr){
                terminated = true;
            } else{
                if (terminated)
                    return false;
                bfsQueue.push(node->left);
                bfsQueue.push(node->right);
            }
        }

        return true;
    }
};