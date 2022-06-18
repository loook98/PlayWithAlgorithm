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
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        if (A == nullptr || B == nullptr)
            return false;

        if (A->val == B->val && doesTree1HasTree2(A, B))
            return true;

        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    //判断root1为根的树是否包含root2为根的树。
    bool doesTree1HasTree2(TreeNode *root1, TreeNode *root2){
        if(root2 == nullptr){
            return true;
        }

        if (root1 == nullptr)
            return false;

        if (root1->val != root2->val)
            return false;

        return doesTree1HasTree2(root1->left, root2->left) &&
                doesTree1HasTree2(root1->right, root2->right);
    }
};