#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode"

using namespace std;

vector<double> solution637_0(TreeNode*root){
    vector<double> ans;
    queue<TreeNode*> que;
    TreeNode *cur = root;
    if (cur != nullptr) que.push(cur);
    while (!que.empty()) {
        int size = que.size();
        double sum = 0;
        for (int i = 0; i < size; ++ i) {
            cur = que.front();
            que.pop();
            sum += cur->val;
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }
        ans.push_back(sum / size);
    }
    return ans;
}