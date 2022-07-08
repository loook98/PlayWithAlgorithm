#include <bits/stdc++.h>

using namespace std;

//二叉树的序列化与反序列化
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
        ostringstream oss;

        queue<TreeNode *> bfsQ;
        bfsQ.push(root);
        while (!bfsQ.empty()){
            TreeNode *node = bfsQ.front();
            bfsQ.pop();

            if (node == nullptr){
                oss << "null" << " ";
            } else{
                oss << node->val << " ";
                bfsQ.push(node->left);
                bfsQ.push(node->right);
            }
        }

        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        istringstream iss(data);

        vector<TreeNode *> nodes;
        string tmp;
        while (iss >> tmp){
            if (tmp == "null"){
                nodes.push_back(nullptr);
            } else{
                nodes.push_back(new TreeNode(stoi(tmp)));
            }
        }


        int curIndex = 0, childIndex = 1;
        while (childIndex < nodes.size()){
            if (nodes[curIndex] != nullptr){
                nodes[curIndex]->left = nodes[childIndex++];
                nodes[curIndex]->right = nodes[childIndex++];
            }
            curIndex++;
        }

        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));