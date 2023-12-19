#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include "TreeNode"

using namespace std;


TreeNode* recur105(vector<int>& preorder, int pre_bg, int pre_ed, vector<int>& inorder, int in_bg, int in_ed){
    int len = in_ed - in_bg;
    int root_val = preorder[pre_bg];
    TreeNode* left = nullptr, * right = nullptr;

    if (len == 1) {
        return new TreeNode(root_val, left, right);
    }
    int i = 0;
    for (i = 0; i < len; ++i) {
        if (inorder[in_bg + i] == root_val) break;
    }
    if (i) left = recur105(preorder, pre_bg + 1, pre_bg + 1 + i, inorder, in_bg, in_bg + i);
    if (in_ed - in_bg - i - 1) right = recur105(preorder, pre_bg + 1 + i, pre_ed, inorder, in_bg + i + 1, in_ed);
    return new TreeNode(root_val, left, right);
}

TreeNode* solution105_0(vector<int>& preorder, vector<int>& inorder) {
    if (inorder.empty()) return nullptr;
    return recur105(preorder, 0, preorder.size(), inorder, 0, inorder.size());
}