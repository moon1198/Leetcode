#include <bits/stdc++.h>

using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    vector<bool>visited (rooms.size(), false);
    visited[0] = true;

    queue<int>que;
    que.push(0);
    
    while (!que.empty()) {
        int cur_room = que.front();
        que.pop();

        for (int i = 0; i < rooms[cur_room].size(); ++ i) {
            if (!visited[rooms[cur_room][i]]) {
                que.push(rooms[cur_room][i]);
                visited[rooms[cur_room][i]] = true;
            }
        }
    }
    for (bool it : visited) {
        if (!it) return false;
    }
    return true;
}