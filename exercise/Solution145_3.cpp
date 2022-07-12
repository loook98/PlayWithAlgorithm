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

struct Data{
    TreeNode *node;
    int visitedNum;
    Data(TreeNode *_node, int _num) : node(_node), visitedNum(_num){}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *cur = root;
        stack<Data> postorderStack;

        while (!postorderStack.empty() || cur != nullptr){
            while (cur != nullptr){
                postorderStack.push({cur, 1});
                cur = cur->left;
            }

            Data tmp = postorderStack.top();
            postorderStack.pop();

            if (tmp.visitedNum == 1){
                postorderStack.push({tmp.node, 2});
                cur = tmp.node->right;
            } else{ // == 2
                res.push_back(tmp.node->val);
            }
        }

        return res;
    }
};