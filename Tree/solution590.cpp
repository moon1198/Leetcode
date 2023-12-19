#include <vector>
#include <queue>
#include <algorithm>
#include "Node1"

using namespace std;

//N叉树的后序遍历
void recur590(Node* cur, vector<int>& ans) {
    if (cur == nullptr) return;
    int size = cur->children.size();
    for (int i = 0; i < size; ++ i) {
        recur590(cur->children[i], ans);
    }
    ans.push_back(cur->val);
}
vector<int> solution590_0(Node* root) {
    vector<int> ans;
    recur590(root, ans);
    return ans;
}