#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode"

using namespace std;

static vector<int>vec;
void recur530_0(TreeNode *root) {
    if (root == nullptr) return ;
    recur530_0(root->left);
    vec.push_back(root->val);
    recur530_0(root->right);
}
int solution530_0(TreeNode *root) {
    vec.clear();
    recur530_0(root);
    if (vec.size() < 2) return 0;
    int result = INT_MAX;
    int len = vec.size();
    for (int i = 1; i < len; ++ i) {
        result = result > vec[i] - vec[i - 1] ? vec[i] - vec[i - 1] : result;
    }
    return result;
}