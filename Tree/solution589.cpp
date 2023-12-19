#include <vector>
#include <queue>
#include <algorithm>
#include "Node1"

using namespace std;

void recur589(Node* cur, vector<int>& ans) {
    if (cur == nullptr) return;
    int size = cur->children.size();
    ans.push_back(cur->val);
    for (int i = 0; i < size; ++ i) {
        recur589(cur->children[i], ans);
    }
}
vector<int> solution589_0(Node* root) {
    vector<int> ans;
    recur589(root, ans);
    return ans;
}