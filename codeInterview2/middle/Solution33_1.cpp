#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int> &postorder) {
        return verify(postorder, 0, postorder.size() - 1);
    }

    //判断子树postorder[l...r]是不是一颗二叉搜索树
    bool verify(vector<int> &postorder, int l, int r) {
        if (l >= r)
            return true;

        //右子树[rightL...rightR)
        int rightR = r;
        int rightL = r;
        while (rightL - 1 >= l && postorder[rightL - 1] > postorder[r]) {
            rightL--;
        }

        //左子树[leftL...leftR)
        int leftR = rightL;
        int leftL = rightL;
        while (leftL - 1 >= l && postorder[leftL - 1] < postorder[r]) {
            leftL--;
        }

        //左子树和右子树的节点数不够[l...r)则返回false，否则递归判断左右子树
        if ((leftR - leftL + rightR - rightL) != (r - l))
            return false;

        return verify(postorder, leftL, leftR - 1) &&
               verify(postorder, rightL, rightR - 1);
    }
};