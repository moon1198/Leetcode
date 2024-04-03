#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

long cnt = 0;

void recur(TreeNode *root, long sum) {
    if (!root) {
        return ;
    }
    sum -= root->val;
    if (sum == 0) ++ cnt;
    recur(root->left, sum);
    recur(root->right, sum);
}

long pathSum0(TreeNode* root, long targetSum) {
    if (!root) return cnt;
    recur(root, targetSum);

    pathSum0(root->left, targetSum);
    pathSum0(root->right, targetSum);
    return cnt;
}

unordered_map<long, int>presum;

int preorder(TreeNode *root, long sum, long targetSum) {
    if (!root) return 0;
    int ret = 0;
    sum += root->val;
    if (presum.find(sum - targetSum) != presum.end()) {
        ret += presum[sum - targetSum];
    }

    presum[sum] ++;
    int left = preorder(root->left, sum, targetSum);
    int right = preorder(root->right, sum, targetSum);
    presum[sum] --;
    
    return ret + left + right;
}

long pathSum(TreeNode* root, long targetSum) {
    presum[0] = 1;
    return preorder(root, 0, targetSum);
}








