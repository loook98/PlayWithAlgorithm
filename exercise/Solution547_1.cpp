#include <bits/stdc++.h>

using namespace std;

class UnionFind{
    vector<int> parent;
    vector<int> rank;

public:
    int count; //记录集合个数

    UnionFind(int n){
        parent = vector<int>(n);
        rank = vector<int>(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
        count = n;
    }

    int find(int i){
        while (parent[i] != i){
            i = parent[i];
        }
        return i;
    }

    bool isConnected(int x, int y){
        if (x == y)
            return true;
        else
            return find(x) == find(y);
    }

    void unionElements(int x, int y){
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return;

        int rankRootX = rank[rootX];
        int rankRootY = rank[rootY];
        if (rankRootX > rankRootY){
            parent[rootY] = rootX;
        } else if (rankRootX < rankRootY){
            parent[rootX] = rootY;
        } else{
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        count--;
    }
};

//并查集求解
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1)
                    uf.unionElements(i ,j);
            }
        }

        return uf.count;
    }
};