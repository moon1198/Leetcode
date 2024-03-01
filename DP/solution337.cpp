#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <numeric>
#include "TreeNode.h"

using namespace std;

int recur337_0(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int res1 = root->val;
    if (root->left) res1 += recur337_0(root->left->left) + recur337_0(root->left->right);
    if (root->right) res1 += recur337_0(root->right->left) + recur337_0(root->right->right);

    int res2 = recur337_0(root->left) + recur337_0(root->right);

    return max(res1, res2);

}

static unordered_map <TreeNode*, int> mp;
int recur337_1(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    if(mp[root]) return mp[root];

    int res1 = root->val;
    if (root->left) res1 += recur337_1(root->left->left) + recur337_1(root->left->right);
    if (root->right) res1 += recur337_1(root->right->left) + recur337_1(root->right->right);

    int res2 = recur337_1(root->left) + recur337_1(root->right);

    int res = max(res1, res2);
    mp[root] = res;
    return res;

}

int solution337_0(TreeNode* root) {
    return recur337_0(root);
}