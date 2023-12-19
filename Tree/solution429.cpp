#include <vector>
#include <queue>
#include <algorithm>
#include "Node1"

using namespace std;
vector<vector<int>> solution429_0(Node *root) {
    vector<vector<int>> ans;
    Node *cur = root;
    queue<Node*> que;
    if (cur != nullptr) que.push(cur);
    while (!que.empty()) {
        int size = que.size();
        vector<int> tmp;
        for (int i = 0; i < size; ++ i) {
            cur = que.front();
            que.pop();
            tmp.push_back(cur->val);
            int child_count = cur->children.size();
            for (int j = 0; j < child_count; ++ j) {
                que.push(cur->children[j]);
            }
        }
        ans.push_back(tmp);
    }
    return ans;
}