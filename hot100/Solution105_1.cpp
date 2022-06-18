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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int preIndex = 0; //preorderIndex在各层递归中要对同一个数进行操作。即preorderIndex应该是一个引用。 否则有错误用例 pre[3,1,2,4] in[1,2,3,4]
        return build(preorder, inorder, preIndex, 0, inorder.size()-1);
    }

    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int &preorderIndex, int inorderL, int inorderR) {
        if (inorderL > inorderR)
            return nullptr;

        int mid = -1;
        for (int i = inorderL; i <= inorderR; ++i) {
            if (inorder[i] == preorder[preorderIndex])
                mid = i;
        }

        TreeNode *node = new TreeNode(preorder[preorderIndex]);
        //这里不能用 TreeNode node(preorder[preorderIndex]) ,然后再&取地址返回，会出错
        int newL1 = inorderL, newR1 = mid - 1;
        int newL2 = mid + 1, newR2 = inorderR;
        if (newL1 <= newR1)
            node->left = build(preorder, inorder, ++preorderIndex, newL1, newR1);
        if (newL2 <= newR2)
            node->right = build(preorder, inorder, ++preorderIndex, newL2, newR2);
        return node;
    }
};