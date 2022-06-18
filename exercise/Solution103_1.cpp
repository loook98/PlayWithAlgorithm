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

//层序遍历使用2个栈，而不用队列。
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        stack<TreeNode *> stackLR; //从这个栈取出的元素「先访问左孩子，再访问右孩子」
        stack<TreeNode *> stackRL; //从这个栈取出的元素「先访问右孩子，再访问左孩子」

        vector<vector<int>> res;
        if (root != nullptr)
            stackLR.push(root);
        while (!stackLR.empty() || !stackRL.empty()) {
            vector<int> tmp;
            if (!stackLR.empty()) {
                while (!stackLR.empty()) {
                    TreeNode *node = stackLR.top();
                    stackLR.pop();
                    tmp.push_back(node->val);

                    if (node->left)
                        stackRL.push(node->left);
                    if (node->right)
                        stackRL.push(node->right);
                }
            } else {
                while (!stackRL.empty()) {
                    TreeNode *node = stackRL.top();
                    stackRL.pop();
                    tmp.push_back(node->val);

                    if (node->right)
                        stackLR.push(node->right);
                    if (node->left)
                        stackLR.push(node->left);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};