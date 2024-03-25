#include <bits/stdc++.h>
using namespace std;

int findfa(vector<int>& fa, int i) {
    if (fa[i] == i) {
        return i;
    } else {
        fa[i] = findfa(fa, fa[i]);
        return fa[i];
    }
}

bool unionn(vector<int>& fa, int i, int j) {
    int u = findfa (fa, i);
    int v = findfa (fa, j);
    if (u == v) {
        return false;
    }
    fa[j] = u;
    return true;
}

bool isTreeAfterRemoveEdge(vector<vector<int>>& edges, int index) {
    int n = edges.size();
    vector<int>fa(n + 1, 0);
    for (int i = 1; i < n + 1; ++ i) {
        fa[i] = i;
    }
    for (int i = 0; i < n; ++ i) {
        if (i != index) {
            if (!unionn(fa, edges[i][0], edges[i][1])) {
                return false;
            }
        }
    }
    return true;
}

vector<int> getRemoveEdge(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int>fa(n + 1, 0);
    for (int i = 1; i < n + 1; ++ i) {
        fa[i] = i;
    }
    for (int i = 0; i < n; ++ i) {
        if (!unionn(fa, edges[i][0], edges[i][1])) {
            return edges[i];
        }
    }
    return {};
}

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    //a circle or 
    int n = edges.size();
    //0: 出度, 1: 入度
    vector<int> in_degree(n + 1, 0);
    for (auto &it : edges) {
        in_degree[it[1]] += 1;
    }
    vector<int> vec;
    for (int i = n - 1; i >= 0; -- i) {
        if (in_degree[edges[i][1]] == 2) {
            vec.push_back(i);
        }
    }
    if (!vec.empty()) {
        if (isTreeAfterRemoveEdge(edges, vec[0])) {
            return edges[vec[0]];
        } else {
            return edges[vec[1]];
        }
    }

    return getRemoveEdge(edges);
}