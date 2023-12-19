#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode"

using namespace std;

vector<int> solution515_0(TreeNode* root) {
    vector<int> ans;
    queue<TreeNode*> que;
    TreeNode* cur = root;
    if (cur != nullptr) que.push(cur);
    while (!que.empty()) {
        int size = que.size();
        cur = que.front();
        que.pop();
        int big = cur->val;
        if(cur->left) que.push(cur->left);
        if(cur->right) que.push(cur->right);
        for (int i = 1; i < size; ++ i) {
            cur = que.front();
            que.pop();
            big = big > cur->val ? big : cur->val; 
            if(cur->left) que.push(cur->left);
            if(cur->right) que.push(cur->right);
        }
        ans.push_back(big);
    }
    return ans;
}