#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int M, N;
    vector<vector<bool>> visited;
    int res;
    vector<vector<int>> directions = {{-1, 0},
                                      {0,  1},
                                      {1,  0},
                                      {0,  -1}};

    int movingCount(int m, int n, int k) {
        M = m;
        N = n;
        visited = vector<vector<bool>>(M, vector<bool>(N, false));

        findCount(0, 0, k);
        return res;
    }

    void findCount(int curI, int curJ, int k){
        if (!inArea(curI, curJ) || !canVisit(curI, curJ, k) || visited[curI][curJ])
            return;

        res++;
        visited[curI][curJ] = true;
        for (int i = 0; i < 4; ++i) {
            int newI = curI + directions[i][0];
            int newJ = curJ + directions[i][1];
            findCount(newI, newJ, k);
        }
    }

    bool canVisit(int i, int j, int k){
        int sum = 0;
        while (i > 0){
            sum += i % 10;
            i /= 10;
        }
        while (j > 0){
            sum += j % 10;
            j /= 10;
        }

        return sum <= k;
    }

    bool inArea(int i, int j) {
        return (i >= 0 && i < M) && (j >= 0 && j < N);
    }

};