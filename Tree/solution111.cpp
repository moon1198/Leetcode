#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode"

using namespace std;

int solution111_0(TreeNode* root) {
    int ans = 0;
    queue<TreeNode*> que;
    TreeNode* cur = root;
    if (cur != nullptr) que.push(cur);
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; ++ i) {
            cur = que.front();
            que.pop();
            if (!(cur->left || cur->right)) return ++ ans;
            if(cur->left) que.push(cur->left);
            if(cur->right) que.push(cur->right);
        }
        ++ ans;
    }
    return ans;
}


int recur111_1(TreeNode* root) {
    if (root == nullptr) return 0;
    int left = recur111_1(root->left);
    int right = recur111_1(root->right);
    if (left == 0 || right == 0) return left + right + 1;
    return min(left, right) + 1;
}
int solution111_1(TreeNode* root) {
    return recur111_1(root);
}



int recur111_2(TreeNode* root, int depth) {
    if (!(root->left || root->right)) {
        return depth;
    }else if (root->left && root->right) {
        int left = recur111_2(root->left, depth + 1);
        int right = recur111_2(root->right, depth + 1);
        return min(left, right) + 1;
    }else if (root->left) {
        return recur111_2(root->left, depth + 1) + 1; 
    }else if (root->right) {
        return recur111_2(root->right, depth + 1) + 1; 
    }
    return -1;
}
int solution111_2(TreeNode* root) {
    if (root == nullptr) return 0;
    return recur111_2(root, 1);
}