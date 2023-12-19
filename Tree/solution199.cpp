#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode"

using namespace std;

vector<int> solution199_0(TreeNode *root) {
    vector<int> ans;
    queue<TreeNode*> que;
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; ++ i) {
            TreeNode *tmp = que.front();
            if (i == size - 1) {
                ans.push_back(tmp->val);
            }
            que.pop();
            if (tmp->left) que.push(tmp->left);
            if (tmp->right) que.push(tmp->right);
        }
    }
    return ans;
}