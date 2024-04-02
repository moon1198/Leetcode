#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

void inorder (TreeNode *root, int &k, int &ret) {
    if (!root) return;
    inorder(root->left, k, ret);
    if (k == 0) return;
    if (-- k == 0) {
        ret = root->val;
        return;
    }
    inorder(root->right, k, ret);
}

int kthSmallest(TreeNode* root, int k) {
    //中序遍历，即为搜索树从小到大顺序
    int ret;
    inorder(root, k, ret);
    return ret;
}