#include <vector>
#include <queue>
#include <stdexcept>
#include "TreeNode"
using namespace std;

static int sum = 0;
//find the sum of all numbers greater than this node->val
//the solution can easily been find after lining up
void recur538_0(TreeNode *root) {
    if (root == nullptr) return;
    recur538_0(root->right);
    sum += root->val;
    root->val = sum;
    recur538_0(root->left);
}
TreeNode *solution538_0(TreeNode *root) {
    recur538_0(root);
    return root;
}