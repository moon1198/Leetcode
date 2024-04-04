#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> mp;
    //记录入度
    vector<int> vec(numCourses, 0);
    for (auto &it : prerequisites) {
        vec[it[0]] ++;
        mp[it[1]].push_back(it[0]);
    }
    queue<int> que;
    for (int i = 0; i < vec.size(); ++ i) {
        if (vec[i] == 0) {
            que.push(i);
        }
    }
    int visited = 0;
    while (!que.empty()) {
        ++ visited;
        int tmp = que.front();
        que.pop();
        for (auto num : mp[tmp]) {
            -- vec[num];
            if (vec[num] == 0) {
                que.push(num);
            }
        }
    }

    return visited == numCourses;
}