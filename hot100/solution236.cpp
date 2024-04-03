#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;


TreeNode *res = nullptr;
int postorder(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) return 0;
    int flag = 0;
    if (root->val == q->val || root->val == p->val) ++ flag;
    int left = postorder(root->left, p, q);
    int right = postorder(root->right, p, q);
    flag += left;
    flag += right;
    if (!res && flag == 2) res = root;
    return flag;
}


TreeNode* lowestCommonAncestor0(TreeNode* root, TreeNode* p, TreeNode* q) {
    //目标节点的左子树和右子树含有p, q
    postorder(root, p, q);
    return res;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (!(left || right)) return nullptr;
    if (!left) retun right;
    if (!right) retun left;
    return root; //两边都不为空
}
