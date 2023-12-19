#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode"

using namespace std;

vector<vector<int>> solution102_0(TreeNode *root) {
    vector<vector<int>> vec;
    vector<int> tmp_vec;
    queue<TreeNode *> que;
    int pre_count = 0;
    int nxt_count = 0;
    TreeNode *cur = root;

    if (cur == nullptr) return vec;
    que.push(cur);
    ++ pre_count;

    while (!que.empty()) {
        cur = que.front();
        tmp_vec.push_back(cur->val);
        que.pop();
        -- pre_count;
        if (cur->left) {
            que.push(cur->left);
            ++ nxt_count;
        }
        if (cur->right) {
            que.push(cur->right);
            ++ nxt_count;
        }
        if (pre_count == 0) {
            swap(pre_count, nxt_count);
            vec.push_back(tmp_vec);
            tmp_vec.clear();
        }
    }
    return vec;
}
vector<vector<int>> solution102_1(TreeNode *root) {
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
    return ans;
}