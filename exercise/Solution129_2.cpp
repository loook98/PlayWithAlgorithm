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

//非递归DFS,用BFS。
//修改每个节点的值即可。
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        int res = 0;
        queue<TreeNode *> bfsQ;
        if (root)
            bfsQ.push(root);

        while (!bfsQ.empty()){
            TreeNode *node = bfsQ.front();
            bfsQ.pop();

            if (node->left){
                node->left->val += node->val * 10;
                bfsQ.push(node->left);
            }
            if (node->right){
                node->right->val += node->val * 10;
                bfsQ.push(node->right);
            }
            if (node->left == nullptr && node->right == nullptr)
                res += node->val;
        }
        return res;
    }
};