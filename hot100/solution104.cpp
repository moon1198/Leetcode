#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

static int max_depth = 0;
void inorder(TreeNode *root, int depth) {
    if (root == nullptr) {
        max_depth = max(max_depth, depth);
        return;
    }
    ++ depth;
    inorder(root->left, depth);
    inorder(root->right, depth);
}

int inorder1(TreeNode *root) {
    //自底向上
    if (root == nullptr) {
        return 0;
    }
    int left = inorder1(root->left);
    int right = inorder1(root->right);
    return max(left, right) + 1;
}

int maxDepth(TreeNode* root) {
    inorder(root, 0);
    return max_depth;
}