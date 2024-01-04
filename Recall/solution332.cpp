#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

static vector<vector<string>> res;
static vector<string> path;

bool recur332_0(vector<vector<string>> &tickets, vector<bool>used) {
    if (path.size() == tickets.size() + 1) {
        return true;
    }

    for (int i = 0; i < static_cast<int>(tickets.size()); ++ i) {
        // if ("he" == path.back()) {
        if (used[i] == false && tickets[i][0] == path.back()) {
            used[i] = true;
            path.push_back(tickets[i][1]);
            if (recur332_0(tickets, used)) return true;
            used[i] = false;
            path.pop_back();
        }
    }
    return false;
}

vector<string> solution332_0(vector<vector<string>> &tickets) {
    path.clear();
    path.push_back("JFK");
    vector<bool>used(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    recur332_0(tickets, used);
    return path;
}


//sort by pair_first auto 
unordered_map<string, map<string, int>> targets;
bool recur332_1(int len, vector<string> &result) {
    if (static_cast<int>(result.size()) == len + 1) {
        return true;
    }
    for (pair<const string, int> &target : targets[result.back()]) {
        if (target.second > 0) {
            target.second --;
            result.push_back(target.first);
            if (recur332_1(len, result)) return true;
            result.pop_back();
            target.second ++;
        }
    }
    return false;
}

vector<string> solution332_1(vector<vector<string>> &tickets) {
    for (auto &it : tickets) {
        targets[it[0]][it[1]] ++;
    }
    vector<string> result;
    result.push_back("JFK");
    recur332_1(tickets.size(), result);
    return result;
}