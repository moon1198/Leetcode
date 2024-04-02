#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;


void inorder(TreeNode *root) {
    if (!root) return;
    // if (!root->left && !root->right) return;

    inorder(root->left);
    inorder(root->right);
    if (!root->left) return;
    TreeNode *left = root->left;
    TreeNode *right = root->right;

    root->left = nullptr;
    root->right = left;
    while (left->right) {
        left = left->right;
    }
    left->right = right;
}

void flatten(TreeNode* root) {
    // inorder(root);
    TreeNode *tmp = root;
    while (tmp) {
        TreeNode *left = tmp->left;
        TreeNode *right = tmp->right;
        if (!left) {
            tmp = tmp->right;
            continue;
        }
        tmp->left = nullptr;
        tmp->right = left;
        while (left->right) {
            left = left->right;
        }
        left->right = right;

        tmp = tmp->right;
    }
}