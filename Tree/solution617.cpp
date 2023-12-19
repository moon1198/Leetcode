#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode"

using namespace std;

TreeNode* recur617_0(TreeNode* root1, TreeNode* root2) {
    TreeNode* cur, * left, * right;
    if (!(root1 || root2)) {
        return nullptr;
    }else if (root1 && root2) {
        cur = new TreeNode(root1->val + root2->val);
        left = recur617_0(root1->left, root2->left);
        right = recur617_0(root1->right, root2->right);
    }else if (root1 && root2 == nullptr) {
        cur = new TreeNode(root1->val);
        left = recur617_0(root1->left, nullptr);
        right = recur617_0(root1->right, nullptr);
    }else if (root1 == nullptr && root2) {
        cur = new TreeNode(root2->val);
        left = recur617_0(nullptr, root2->left);
        right = recur617_0(nullptr, root2->right);
    }
    cur->left = left;
    cur->right = right;
    return cur;
}
TreeNode* solution617_0(TreeNode* root1, TreeNode* root2) {
    return recur617_0(root1, root2);
}


TreeNode* recur617_1(TreeNode* root1, TreeNode* root2) {
    TreeNode* cur, * left, * right;
    if (root1 == nullptr) return root2;
    if (root2 == nullptr) return root1;

    //(root1 && root2)
    cur = root1;
    left = recur617_1(root1->left, root2->left);
    right = recur617_1(root1->right, root2->right);

    cur->left = left;
    cur->right = right;
    cur->val += root2->val;
    return cur;
}
TreeNode* solution617_1(TreeNode* root1, TreeNode* root2) {
    return recur617_1(root1, root2);
}