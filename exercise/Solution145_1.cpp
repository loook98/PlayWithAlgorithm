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
    //后续遍历，教科书经典非递归实现，与先序和中序差别较大
    //对于每一个节点，沿着左节点一直向下，并入栈，直到为左子树null为止。 【有右节点的树会进栈两次】
    //
    //此时该结点出现在栈顶，将该节点从栈顶弹出使用该节点.
    //if:
    // 如果该节点的右子树为null 或 right是上一个遍历完成的子树
    // 则访问该节点，标记pre【遍历完成的子树根】为该节点，root标记为null【下次就会从栈中取一个节点】
    //else:
    //right没被访问，则将该节点再次入栈,考虑该节点的右子树
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stack;
        TreeNode *prev = nullptr; //prev为上一个已经遍历完成的树的根。

        while (root != nullptr || !stack.empty()) {
            while (root != nullptr) {
                stack.emplace(root);
                root = root->left;
            }

            root = stack.top();
            stack.pop();
            if (root->right == nullptr || root->right == prev) {
                res.emplace_back(root->val);
                prev = root;
                root = nullptr;
            } else {
                stack.emplace(root);
                root = root->right;
            }
        }
        return res;
    }
};

