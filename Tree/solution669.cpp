#include <vector>
#include <queue>
#include <algorithm>
#include <stdexcept>
#include "TreeNode"
using namespace std;


TreeNode *recur669_0(TreeNode *root, int low, int high) {
    if (root == nullptr) return nullptr;
    //check the node is vaild, if not, pass this node's one childern tree.
    //and return his child tree's ret
    if (root->val < low) {
        return recur669_0(root->right, low, high);
    }
    if (root->val > high) {
        return recur669_0(root->left, low, high);
    }
    //if the node is vaild, maintain the node and refresh his child node
    root->left = recur669_0(root->left, low, high);
    root->right = recur669_0(root->right, low, high);
    return root;
}

TreeNode *solution669_0(TreeNode *root, int low, int high) {
    return recur669_0(root, low, high);
}