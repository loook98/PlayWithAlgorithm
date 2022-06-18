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
    //层序遍历，看了题解。用到了ostringstream和istringstream.
    //用" "来分隔各个节点，用istringstream来取出各个节点很方便
    //先生成节点之后再为各个节点更新left和right
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr)
            return "";

        ostringstream sOut;
        queue<TreeNode *> queue;
        queue.emplace(root);
        while (!queue.empty()) {
            TreeNode *node = queue.front();
            queue.pop();
            if (node == nullptr) {
                sOut << "null" << " ";
            } else {
                sOut << node->val << " ";
                queue.emplace(node->left);
                queue.emplace(node->right);
            }
        }
        return sOut.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.empty())
            return nullptr;
        istringstream sIn(data);
        //把data中的所有元素存起来
        vector<TreeNode *> nodes;
        string temp;
        while (sIn >> temp) {//会自己根据" "分开
            if (temp == "null")
                nodes.emplace_back(nullptr);
            else{
                nodes.emplace_back(new TreeNode(stoi(temp)));
            }
        }

        int pos = 1;
        for (int i = 0; i < nodes.size(); ++i) {
            if (nodes[i] != nullptr){
                nodes[i]->left = nodes[pos++];
                nodes[i]->right = nodes[pos++];
            }
        }
        return nodes[0];
    }
};