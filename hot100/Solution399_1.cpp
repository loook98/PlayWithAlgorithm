#include <bits/stdc++.h>

using namespace std;

//dfs求解
class Solution {
public:
    //两个全局变量
    vector<double> res;
    bool Notfound;

    void dfs(unordered_map<string, vector<pair<string, double>>>& g, unordered_map<string, int>& visited,
             const string& cur, const string& target, const double path){
        if (Notfound == false)
            return;

        if (cur == target){
            Notfound = false;
            res.push_back(path);
            return;
        }

        for (int i = 0; i < g[cur].size(); ++i) {
            if (visited[g[cur][i].first] == 0){
                visited[g[cur][i].first] = 1;
                dfs(g, visited, g[cur][i].first, target, path * g[cur][i].second);
                visited[g[cur][i].first] = 0;
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        unordered_map<string, int> visited;

        //构建无向图
        for (int i = 0; i < equations.size(); ++i) {
            graph[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));
            graph[equations[i][1]].push_back(make_pair(equations[i][0], 1.0/values[i]));
        }

        //遍历queries，对每一组进行dfs
        for (int i = 0; i < queries.size(); ++i) {
            if (graph.find(queries[i][0]) == graph.end()){
                res.push_back(-1.0);
                continue;
            }

            Notfound = true;
            visited[queries[i][0]] = 1;
            dfs(graph, visited, queries[i][0], queries[i][1], 1);
            visited[queries[i][0]] = 0;

            if (Notfound)
                res.push_back(-1.0);
        }
        return res;
    }
};