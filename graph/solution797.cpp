#include <vector>
#include <stack>

using namespace std;


void recur797_0(vector<int>& node, vector<int>& path, int target, vector<vector<int>>& ans, vector<vector<int>>& graph) {
    for (int i : node) {
        path.push_back(i);
        if (i == target) {
            ans.push_back(path);
            path.pop_back();
            continue;
        }
        recur797_0(graph[i], path, target, ans, graph);
        path.pop_back();
    }
}


vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> ans;
    vector<int> path;
    path.push_back(0);
    
    recur797_0(graph[0], path, graph.size() - 1, ans, graph);
    return ans;

}