#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode"

using namespace std;

vector<vector<int>> solution107_1(TreeNode *root) {
    vector<vector<int>> ans;
    queue<TreeNode*> que;
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; ++ i) {
            TreeNode *tmp = que.front();
            que.pop();
            vec.push_back(tmp->val);
            if (tmp->left) que.push(tmp->left);
            if (tmp->right) que.push(tmp->right);
        }
        ans.push_back(vec);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}