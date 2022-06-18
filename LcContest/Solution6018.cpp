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
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
        unordered_map<int,TreeNode*> map;
        for (auto desc : descriptions) {
            if (!map.count(desc[0]))
                map.insert(make_pair(desc[0], new TreeNode(desc[0])));
            if (!map.count(desc[1]))
                map.insert(make_pair(desc[1], new TreeNode(desc[1])));
        }

        for (auto desc: descriptions) {
            if (desc[2]){
                map[desc[0]]->left = map[desc[1]];
            } else{
                map[desc[0]]->right = map[desc[1]];
            }
        }

        unordered_set<int> leave;
        for (auto desc: descriptions) {
            leave.insert(desc[1]);
        }

        int root;
        for (auto desc: descriptions) {
            if (!leave.count(desc[0])){
                root = desc[0];
                break;
            }
        }
        return map[root];
    }
};