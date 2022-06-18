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
    int preorderIndex = 0;

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder, inorder, 0, inorder.size() - 1);
    }

    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int inorderL, int inorderR) {
        if (inorderL > inorderR)
            return nullptr;
        if (inorderL == inorderR) {
            preorderIndex++;
            return new TreeNode(inorder[inorderL]);
        }

        int i;
        for (i = inorderL; i <= inorderR; ++i) {
            if (inorder[i] == preorder[preorderIndex])
                break;
        }
        preorderIndex++;

        TreeNode *root = new TreeNode(inorder[i]);
        root->left = build(preorder, inorder, inorderL, i - 1);
        root->right = build(preorder, inorder, i + 1, inorderR);
        return root;
    }
};