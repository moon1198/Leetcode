#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

void preorder(TreeNode *root) {
    if (root == nullptr) {
        return ;
    }
    swap(root->left, root->right);
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode *root) {
    if (root == nullptr) {
        return ;
    }
    inorder(root->left);
    swap(root->left, root->right);
    inorder(root->left);
}

void postorder(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    swap(root->left, root->right);
}

TreeNode* invertTree(TreeNode* root) {
    postorder(root);
    return root;
}