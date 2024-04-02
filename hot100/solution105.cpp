#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

TreeNode *recur (vector<int>& preorder, vector<int>& inorder, int l1, int r1, int l2, int r2) {
    if (l1 >= r1) return nullptr;
    int val = preorder[0];
    int i;
    for (i = l2; i < r2; ++ i) {
        if (inorder[i] == val) {
            break;
        }
    }
    int len = i - l2;
    TreeNode *root = new TreeNode(val);

    root->left = recur(preorder, inorder, l1 + 1, l1 + len + 1, l2, l2 + len);
    root->right = recur(preorder, inorder, l1 + len + 1, r1, l2 + len + 1, r2);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return recur(preorder, inorder, 0, preorder.size(), 0, inorder.size());
}