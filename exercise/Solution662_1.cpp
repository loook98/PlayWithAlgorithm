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

struct AnnotatedNode{
    TreeNode *node;
    unsigned long long depth, pos; //depth为当前深度，pos为在本层的序号

    AnnotatedNode(TreeNode *_node, unsigned long long _depth, unsigned long long _pos): node(_node), depth(_depth), pos(_pos){}
};

//BFS,队列中放AnnotatedNode结构体
class Solution {
public:
    int widthOfBinaryTree(TreeNode *root) {
        queue<AnnotatedNode> bfsQ;
        bfsQ.push(AnnotatedNode(root, 0, 0));

        unsigned long long res = 0;
        unsigned long long curDepth = -1, left = 0; //left记录每层最左边元素的序号
        while (!bfsQ.empty()){
            AnnotatedNode aNode = bfsQ.front();
            bfsQ.pop();

            if (aNode.node != nullptr){
                bfsQ.push(AnnotatedNode(aNode.node->left, aNode.depth + 1, 2 * aNode.pos));
                bfsQ.push(AnnotatedNode(aNode.node->right, aNode.depth + 1, 2 * aNode.pos + 1));

                if (aNode.depth != curDepth){
                    curDepth = aNode.depth;
                    left = aNode.pos;
                }

                res = max(res, aNode.pos - left + 1);
            }
        }

        return (int)res;
    }
};