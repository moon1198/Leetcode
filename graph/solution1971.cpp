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

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    //init
    vector<int> fa(n, 0);
    for (int i = 0; i < n; ++ i) {
        fa[i] = i;
    }
    for (int i = 0; i < edges.size(); ++ i) {
        unionn(fa, edges[i][0], edges[i][1]);
    }

    if (findfa(fa, source) == findfa(fa, destination)) {
        return true;
    }
    return false;
}