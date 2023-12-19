#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode"

using namespace std;

int recur222_0(TreeNode* root) {
    static int cnt = 0;
    int left = 0;
    int right = 0;
    TreeNode* cur = root;
    while (cur != nullptr) {
        ++ left;
        cur = cur->left;
    }
    cur = root;
    while (cur != nullptr) {
        ++ right;
        cur = cur->right;
    }
    if (left == right) {
        return cnt += (1 << left) - 1;
    }else {
        cnt ++;
        recur222_0(root->left);
        recur222_0(root->right);
    }
    return cnt;
}


int recur222_1(TreeNode* root) {
    int left = 0;
    int right = 0;
    TreeNode* cur = root;
    while (cur != nullptr) {
        ++ left;
        cur = cur->left;
    }
    cur = root;
    while (cur != nullptr) {
        ++ right;
        cur = cur->right;
    }
    if (left == right) {
        return (1 << left) - 1;
    }else {
        return recur222_1(root->left) + recur222_1(root->right) + 1;
    }
}


int solution222_0(TreeNode* root) {
    return recur222_1(root);
}

