#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;

        //stack1和stack2各代表一层的元素，两个同一时间必有一个为空.两个都为空时结束。
        stack<TreeNode *> stack1; //stack1插入元素时，先插左节点，再插右节点。
        stack<TreeNode *> stack2; //stack2插入元素时，先插右节点，再插左节点。

        res.push_back({root->val});
        if (root->left)
            stack1.push(root->left);
        if (root->right)
            stack1.push(root->right);

        //每次循环处理一层
        while (!stack1.empty() || !stack2.empty()) {
            vector<int> curLevel;
            if (!stack1.empty()) {
                while (!stack1.empty()) {
                    TreeNode *tmp = stack1.top();
                    stack1.pop();

                    curLevel.push_back(tmp->val);
                    if (tmp->right)
                        stack2.push(tmp->right);
                    if (tmp->left)
                        stack2.push(tmp->left);
                }
            } else {
                while (!stack2.empty()) {
                    TreeNode *tmp = stack2.top();
                    stack2.pop();

                    curLevel.push_back(tmp->val);
                    if (tmp->left)
                        stack1.push(tmp->left);
                    if (tmp->right)
                        stack1.push(tmp->right);
                }
            }
            //将得到的当前这层的遍历顺序添加到结果
            res.push_back(curLevel);
        }

        return res;
    }
};