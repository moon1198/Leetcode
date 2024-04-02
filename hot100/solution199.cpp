#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

void preorder(TreeNode *root, int depth, int &max_depth, vector<int> &vec) {
    if (!root) return;
    if (depth + 1 > max_depth) {
        vec.push_back(root->val);
        max_depth = depth + 1;
    }
    preorder(root->right, depth + 1, max_depth, vec);
    preorder(root->left, depth + 1, max_depth, vec);
}

void preorder(TreeNode *root, int depth, vector<int> &vec) {
    if (!root) return;
    int max_depth = vec.size();
    if (depth + 1 > max_depth) {
        vec.push_back(root->val);
        max_depth = depth + 1;
    }
    preorder(root->right, depth + 1, vec);
    preorder(root->left, depth + 1, vec);
}

vector<int> rightSideView(TreeNode* root) {
    //先右子节点后左子节点的前序遍历
    //记录深度，高于此深度的方可写入
    vector<int> vec;
    preorder(root, 0, vec);
    return vec;
}