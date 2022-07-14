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

struct BfsNode {
    TreeNode *node;
    int level; // 第几层
    unsigned long long num; // 本层的第几个元素

    // 不写构造函数好像也可以
    //BfsNode(TreeNode *_node, int _level, unsigned long long _num) : node(_node), level(_level), num(_num){}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode *root) {
        unsigned long long res = 0;

        queue<BfsNode> bfsQ;
        bfsQ.push({root, 0, 0});
        int curLevel = -1;
        unsigned long long left = 0; //本层节点的最左侧
        while (!bfsQ.empty()) {
            auto bfsNode = bfsQ.front();
            bfsQ.pop();

            if (bfsNode.node != nullptr) {
                if (bfsNode.level != curLevel) {
                    curLevel = bfsNode.level;
                    left = bfsNode.num;
                }

                res = max(res, bfsNode.num - left + 1);
                bfsQ.push({bfsNode.node->left, bfsNode.level + 1, bfsNode.num * 2});
                bfsQ.push({bfsNode.node->right, bfsNode.level + 1, bfsNode.num * 2 + 1});
            }
        }

        return (int)res;
    }
};