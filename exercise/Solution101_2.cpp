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

//迭代，层序遍历
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        queue<pair<TreeNode *, int>> bfs; //{node,层号}
        int lastLevel = -1;
        vector<TreeNode *> level; //用于判断一层是不是对称
        bfs.push({root, 0});

        while (!bfs.empty()){
            auto pair = bfs.front();
            bfs.pop();

            if (pair.second != lastLevel){
                if (lastLevel != -1 && lastLevel != 0){ //第0层只有root，一定对称
                    //判断上层是否对称
                    int l = 0, r = level.size() - 1;
                    int nullptrNUm = 0;
                    while (l < r){
                        if (level[l] == nullptr && level[r] == nullptr)
                            nullptrNUm += 2;
                        if (level[l] == nullptr && level[r] != nullptr)
                            return false;
                        if (level[l] != nullptr && level[r] == nullptr)
                            return false;
                        if ((level[l] != nullptr && level[r] != nullptr) &&
                            (level[l]->val != level[r]->val))
                            return false;
                        l++;
                        r--;
                    }
                    if (nullptrNUm == level.size())
                        break;
                }

                //重新开始记录本层
                level.clear();
                level.push_back(pair.first);
                lastLevel = pair.second;
            } else{
                level.push_back(pair.first);
            }

            if (pair.first){
                bfs.push({pair.first->left, pair.second + 1});
                bfs.push({pair.first->right, pair.second + 1});
            } else{
                bfs.push({nullptr, pair.second + 1});
                bfs.push({nullptr, pair.second + 1});
            }
        }

        return true;
    }
};