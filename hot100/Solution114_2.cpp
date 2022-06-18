#include <bits/stdc++.h>

using namespace std;

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
    void flatten(TreeNode *root) {
        TreeNode *cur = root;
        while (cur != nullptr){
            if (cur->left != nullptr){
                TreeNode *next = cur->left;
                TreeNode *predecessor = cur->left;
                while (predecessor->right != nullptr)
                    predecessor = predecessor->right;
                predecessor->right = cur->right;

                cur->left = nullptr;
                cur->right = next;
            }
            cur = cur->right;
        }
    }
};