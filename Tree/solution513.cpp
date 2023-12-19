#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode"

using namespace std;

int solution513_1(TreeNode* root) {
    queue<TreeNode*> que;
    TreeNode* cur = root;
    int ans = 0;
    if (cur != nullptr) {
        que.push(cur);
        ans = cur->val;
    }
    while (!que.empty()) {
        int size = que.size();
        if (size != 0) ans = que.front()->val;
        for (int i = 0; i < size; ++ i) {
            cur = que.front();
            que.pop();
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }
    }
    return ans;
}

int depths = 0;
int ans = 0;
void recur513_0(TreeNode* root, int depth) {
    if (!(root->left || root->right)) {
        if (depth > depths) {
            depths = depth;
            ans = root->val;
        }
        return ;
    }
    if (root->left) recur513_0(root->left, depth + 1);
    if (root->right) recur513_0(root->right, depth + 1);
}
int solution513_0(TreeNode* root) {
    recur513_0(root, 1);
    return ans;
}