#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

#include "TreeNode"
using namespace std;

static int ans = 0;
int recur968_0(TreeNode *root) {

    //three state ; -1: the child of monitor; 0: monitor; 1: the father of monitor
    if (root == nullptr) return -1;
    int left = -1, right = -1;
    left = recur968_0(root->left);
    right = recur968_0(root->right);
    int val = -2;
    if (left == 0 || right == 0) {
        val = 0;
    }else {
        val = max(left, right);
    }
    switch (val) {
        case -1: return 0; break;
        case 0: ++ ans; return 1; break;
        case 1: return -1; break;
        default: cout << "can't reach to here!" << endl; break;
    }
    return -2;

}
int solution968_0(TreeNode *root) {
    int ret = recur968_0(root);
    if (ret == 0) {
        ++ ans;
    }
    return ans;
}

int recur968_1(TreeNode *root) {
    //three state ; 0: no see; 1: monitor; 2: see
    if (root == nullptr) return 0;

    int left = -1, right = -1;
    left = recur968_1(root->left);
    right = recur968_1(root->right);
    int val = -1;
    if (left == 1 || right == 1) {
        val = 1;
    }else {
        val = max(left, right);
    }
    switch (val) {
        case 0: return 1; break;
        case 1: ++ ans; return 2; break;
        case 2: return 0; break;
        default: cout << "can't reach to here!" << endl; break;
    }
    return -1;

}
int solution968_1(TreeNode *root) {
    int ret = recur968_1(root);
    if (ret == 1) {
        ++ ans;
    }
    return ans;
}