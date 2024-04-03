#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;


int max_res = INT_MIN;
int postorder(TreeNode *root) {
    if (!root) return 0;
    int left = postorder(root->left);
    int right = postorder(root->right);

    //获取当前最大值
    int ret = root->val;
    ret = ret + (left > 0 ? left : 0);
    ret = ret + (right > 0 ? right : 0);
    max_res = max(max_res, ret);

    //向上传递
    ret = root->val + max(left, right);
    ret = max(ret, 0);
    return ret;
}

int maxPathSum(TreeNode* root) {
    postorder(root);
    return max_res;
}