#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode"

using namespace std;

static vector<vector<int>> ans;
static vector<int> path;
void recur113_0(TreeNode* root, int count) {
    if (root == nullptr) return;
    path.push_back(root->val);
    if (!(root->left || root->right) && count == root->val) ans.push_back(path); 
    if (root->left) {
        recur113_0(root->left, count - root->val);
        path.pop_back();
    }
    if (root->right) {
        recur113_0(root->right, count - root->val);
        path.pop_back();
    }
}
vector<vector<int>> solution113_0(TreeNode* root, int targetSum) {
    recur113_0(root, targetSum);
    return ans;
}