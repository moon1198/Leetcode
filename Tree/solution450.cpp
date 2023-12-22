#include <vector>
#include <queue>
#include <algorithm>
#include <stdexcept>
#include "TreeNode"
using namespace std;

TreeNode *recur450_0(TreeNode *root, int key) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->val == key) {

        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }else if (root->left == nullptr) {
            TreeNode *tmp = root->right;
            delete root;
            return tmp;
        }else if (root->right == nullptr) {
            TreeNode *tmp = root->left;
            delete root;
            return tmp;
        }else{
            TreeNode *tmp = root->right;
            while (tmp->left) {
                tmp = tmp->left;
            }
            tmp->left = root->left;
            tmp = root->right;
            delete root;
            return tmp;
        }
    }
    if (root->val > key) root->left = recur450_0(root->left, key);
    if (root->val < key) root->right = recur450_0(root->right, key);
    return root;
}

TreeNode *recur450_1(TreeNode *root, int key) {
    if (root == nullptr) return nullptr;
    if (root->val == key) {
        if (root->right == nullptr) {
            return root->left;
        }
        auto cur = root->right;
        while (cur->left) {
            cur = cur->left;
        }
        swap(cur->val, root->val);
    }
    root->left = recur450_1(root->left, key);
    root->right = recur450_1(root->right, key);
    return root;
}

TreeNode *solution450_0(TreeNode *root, int key) {
}