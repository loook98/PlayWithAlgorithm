#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr)
            return "";

        ostringstream oss;
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);

        while (!bfsQueue.empty()){
            TreeNode *cur = bfsQueue.front();
            bfsQueue.pop();

            if (cur != nullptr){
                bfsQueue.push(cur->left);
                bfsQueue.push(cur->right);

                oss << cur->val << " ";
            } else{
                oss << "null" << " ";
            }
        }
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.empty())
            return nullptr;

        istringstream iss(data);
        string tmp;
        vector<TreeNode*> nodes;
        while (iss >> tmp){
            if (tmp == "null"){
                nodes.push_back(nullptr);
            } else{
                nodes.push_back(new TreeNode(stoi(tmp)));
            }
        }

        int index = 1;
        for (int i = 0; i < nodes.size(); ++i) {
            if (nodes[i] != nullptr){
                nodes[i]->left = nodes[index++];
                nodes[i]->right = nodes[index++];
            }
        }

        return nodes[0];
    }
};
