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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int inL, int inR, int postL, int postR) {
        if (postL > postR)
            return nullptr;

        if (postL == postR) {
            return new TreeNode(postorder[postR]);
        }

        //当前子树的根为当前子树后序遍历的最后一个节点
        TreeNode *root = new TreeNode(postorder[postR]);
        //找到当前根节点在中序遍历中的位置，并依此将中序遍历分为两部分。
        //再根据中序遍历两部分的长度将后序遍历分为两部分。
        int i;
        for (i = inL; i <= inR; ++i) {
            if (inorder[i] == postorder[postR])
                break;
        }
        int leftTreeNum = i - inL;

        root->left = build(inorder, postorder, inL, i - 1, postL, postL + (leftTreeNum - 1));
        root->right = build(inorder, postorder, i + 1, inR, postL + leftTreeNum, postR - 1);

        return root;
    }
};