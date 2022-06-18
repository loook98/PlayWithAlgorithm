#include <bits/stdc++.h>

using namespace std;

//6072. 转角路径的乘积中最多能有几个尾随零
//有问题，输出0
class Solution {
public:
    int res;
    int m, n;
    bool canChangeMainD = true;
    vector<vector<vector<int>>> directions = {{{-1, 0}, {1, 0}},{{0,-1},{0,1}}};

    int maxTrailingZeros(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        res = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                canChangeMainD = true;
                dfs(grid, 1, i, j, 0,0);
                canChangeMainD = true;
                dfs(grid, 1, i, j, 0,1);
                canChangeMainD = true;
                dfs(grid, 1, i, j, 1,0);
                canChangeMainD = true;
                dfs(grid, 1, i, j, 1,1);
            }
        }
        return res;
    }

    //direction: {1上、2下}、{3左、4右}
    void dfs(vector<vector<int>>& grid, int multiVal,int i, int j, int mainD, int subD){
        if (!inArea(i,j))
            return;

        if ((multiVal * grid[i][j]) % 10 == 0){
            int temp = multiVal * grid[i][j];
            int zeroNum = 0;
            while (temp % 10 == 0){
                zeroNum++;
                temp /= 10;
            }
            res = max(res, zeroNum);
        }


        //主方向main,子方向sub
        for (int main = 0; main < 2; ++main) {
            if (main == mainD){
                int nexI = i + directions[main][subD][0];
                int nexJ = j + directions[main][subD][1];
                dfs(grid,multiVal * grid[i][j],nexI, nexJ, main, subD);
            } else{
                if (canChangeMainD){
                    for (int sub = 0; sub < 2; ++sub) {
                        canChangeMainD = false;
                        int nexI = i + directions[main][sub][0];
                        int nexJ = j + directions[main][sub][1];
                        dfs(grid,multiVal * grid[i][j], nexI, nexJ, main, sub);
                        canChangeMainD = true;
                    }
                }
            }
        }
    }

    bool inArea(int i, int j){
        return (i >= 0 && i < m) && (j >= 9 && j < n);
    }
};