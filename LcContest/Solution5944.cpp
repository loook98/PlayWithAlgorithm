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

//现在题号为2906
class Solution {
public:

    bool dfs(TreeNode *root, int value, string &path){
        if (root == nullptr)
            return false;
        if (root->val == value)
            return true;

        path.push_back('L');
        if (dfs(root->left, value, path))
            return true;
        path.pop_back();

        path.push_back('R');
        if (dfs(root->right, value, path))
            return true;
        path.pop_back();
        return false;
    }

    string getDirections(TreeNode *root, int startValue, int destValue) {
        //找到根节点到两个节点的路径
        string pathStart = "", pathDest = "";
        dfs(root, startValue, pathStart);
        dfs(root, destValue, pathDest);

        //消除公共前缀(注意：这个过程中翻转了一次，是为了方便删除公共前缀)
        reverse(pathStart.begin(), pathStart.end());
        reverse(pathDest.begin(), pathDest.end());
        int nS = pathStart.size() - 1, nD = pathDest.size() - 1;
        while (nS >= 0 && nD >= 0){
            if (pathStart[nS] == pathDest[nD]){
                pathStart.pop_back();
                pathDest.pop_back();
                nS--;
                nD--;
                continue;
            } else{
                break;
            }
        }

        //翻转回来
        reverse(pathStart.begin(), pathStart.end());
        reverse(pathDest.begin(), pathDest.end());
        //将start的path调整过来（因为之前是从上往下的，现在得调整成下往上）,然后再把dest的路径加上
        string ret = string(pathStart.size(), 'U') + pathDest;
        return ret;
    }
};