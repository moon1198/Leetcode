#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode"

using namespace std;

int solution104_0(TreeNode* root) {
    int ans = 0;
    queue<TreeNode*> que;
    TreeNode* cur = root;
    if (cur != nullptr) que.push(cur);
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; ++ i) {
            cur = que.front();
            que.pop();
            if(cur->left) que.push(cur->left);
            if(cur->right) que.push(cur->right);
        }
        ++ ans;
    }
    return ans;
}


int recur104(TreeNode* cur, int count) {
    //终结条件，左右都为nullptr，返回count
    //left和right表示left子树和right子树的最大深度
    int left = count;
    int right = count;
    if (cur->left) {
        left = recur104(cur->left, count + 1);
    }
    if (cur->right) {
        right = recur104(cur->right, count + 1);
    }
    return right > left ? right : left;
}
int solution104_1(TreeNode* root) { 
    if (root == nullptr) return 0;
    return recur104(root, 1);
}