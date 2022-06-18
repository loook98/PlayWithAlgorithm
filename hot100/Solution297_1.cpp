#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//前序遍历进行初始化
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        ostringstream os;
        _serialize(root, os);
        return os.str();
    }

    void _serialize(TreeNode *root, ostream &stream){
        if (root == nullptr){
            stream << "$ ";
            return;
        }

        stream << root->val << ' ';
        _serialize(root->left, stream);
        _serialize(root->right, stream);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        TreeNode *root = nullptr;
        istringstream is(data);
        _deserialize(&root, is);
        return root;
    }

    void _deserialize(TreeNode **pRoot, istream &stream){
        string s;
        stream >> s;
        if (s != "$"){
            int number = stoi(s);
            *pRoot = new TreeNode(number);
            (*pRoot)->left = nullptr;
            (*pRoot)->right = nullptr;

            _deserialize(&(*pRoot)->left, stream);
            _deserialize(&(*pRoot)->right, stream);
        }
    }
};