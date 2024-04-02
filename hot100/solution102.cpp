#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode *> que;
    if (root == nullptr) {
        return ans;
    }
    que.push(root);
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; ++ i) {
            TreeNode *tmp = que.front();
            vec.push_back(tmp->val);
            que.pop();
            if (tmp->left) que.push(tmp->left);
            if (tmp->right) que.push(tmp->right);
        }
        ans.push_back(vec);
    }
    return ans;
}