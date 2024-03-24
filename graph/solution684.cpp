#include <bits/stdc++.h>
using namespace std;

int findfa (vector<int> &fa, int i) {
    if (fa[i] != i) {
        int tmp = findfa(fa, fa[i]);
        fa[i] = tmp;
        return tmp;
    }else {
        return i;
    }
}

void unionn(vector<int> &fa, int i, int j) {
    int ifa = findfa(fa, i);
    int jfa = findfa(fa, j);
    fa[ifa] = jfa;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    //init
    vector<int> fa(n + 1, 0);
    for (int i = 1; i < n + 1; ++ i) {
        fa[i] = i;
    }
    int i;
    for (i = 0; i < n; ++ i) {
        if (findfa(fa, edges[i][0]) == findfa(fa, edges[i][1])) {
            break;
        }
        unionn(fa, edges[i][0], edges[i][1]);
    }
    return edges[i];
}