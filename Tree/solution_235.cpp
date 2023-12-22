#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode"

TreeNode *solution235_0(TreeNode *root, TreeNode *p, TreeNode *q) {
    TreeNode *cur = root;
    while (cur != nullptr) {
        if (cur->val > p->val && cur->val > q->val) {
            cur = cur->left;
        }else if (cur->val < p->val && cur->val < q->val) {
            cur = cur->right;
        }else if ((cur->val <= p->val && cur->val >= q->val) || (cur->val >= p->val && cur->val <= q->val)) {
            return cur;
        }
    }
    return nullptr;
}