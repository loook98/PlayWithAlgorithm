#include <bits/stdc++.h>

using namespace std;

class UnionFind{//quick union，基于rank的优化
private:
    vector<int> parent;
    vector<int> rank; //记录层数
    int count; //数据个数

public:
    explicit UnionFind(int _count){
        count = _count;
        parent = vector<int>(count);
        rank = vector<int>(count, 1);

        for (int i = 0; i < count; ++i) {
            parent[i] = i;
        }
    }

    int find(int p){ //返回p的parent
        while (p != parent[p])
            p = parent[p];

        return p;
    }

    bool isConnected(int p, int q){
        int pRoot = find(p);
        int qRoot = find(q);

        return pRoot == qRoot;
    }

    void unionElements(int p, int q){
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot)
            return;

        int pRank = rank[pRoot];
        int qRank = rank[qRoot];
        if (pRank > qRank){
            parent[qRoot] = pRoot;
        } else if (qRank > pRank){
            parent[pRoot] = qRoot;
        } else{
            parent[pRoot] = qRoot;
            rank[qRoot] += 1;
        }
    }

    void isolate(int p){ //将一个点孤立
        if (p != parent[p]){
            parent[p] = p;
            rank[p] = 1;
        }
    }
};


class Solution {
public:

    static bool cmp(const vector<int> &meeting1, const vector<int> &meeting2){
        return meeting1[2] < meeting2[2];
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        UnionFind uf(n);
        uf.unionElements(0, firstPerson);

        sort(meetings.begin(), meetings.end(), cmp);
        int ms = meetings.size();
        for (int i = 0; i < ms;) {
            int j = i + 1;
            while (j < ms && meetings[j][2] == meetings[i][2]){
                j++;
            }

            for (int k = i; k < j; ++k) {
                uf.unionElements(meetings[k][0],meetings[k][1]);
            }

            for (int k = i; k < j; ++k) {
                if (!uf.isConnected(meetings[k][0], 0)){
                    uf.isolate(meetings[k][0]);
                    uf.isolate(meetings[k][1]);
                }
            }
            i = j;
        }

        vector<int> ret;
        for (int i = 0; i < n; ++i) {
            if (uf.isConnected(0,i))
                ret.emplace_back(i);
        }
        return ret;
    }
};