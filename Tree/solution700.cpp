#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode"

using namespace std;

TreeNode* solution700_0(TreeNode* root, int val) {
    TreeNode* cur = root;
    while (cur != nullptr) {
        if (val == cur->val) {
            return cur;
        }else if (val < cur->val) {
            cur = cur->left;
        }else if (val > cur->val) {
            cur = cur->right;
        }
    }
    return cur;
}