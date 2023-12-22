#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include "TreeNode"


using namespace std;

static set<TreeNode*> trace_p;
static vector<TreeNode*> trace_q;
static vector<TreeNode*> tree_trace;

void recur236_0(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr) return;
    tree_trace.push_back(root);
    if (root == p) trace_p.insert(tree_trace.begin(), tree_trace.end());
    if (root == q) trace_q.insert(trace_q.begin(), tree_trace.begin(), tree_trace.end());
    if (root->left) {
        recur236_0(root->left, p, q);
        tree_trace.pop_back();
    }
    if (root->right) {
        recur236_0(root->right, p, q);
        tree_trace.pop_back();
    }
}

TreeNode *solution236_0(TreeNode *root, TreeNode *p, TreeNode *q) {
    recur236_0(root, p, q);
    while (trace_q.size()) {
        if (trace_p.find(trace_q.back()) != trace_p.end()){
            return trace_q.back();
        }
        trace_q.pop_back();
    }
    return nullptr;
}

static TreeNode *result = nullptr;
int recur236_1(TreeNode *root, TreeNode *p, TreeNode *q) {
    int flag = 0;
    if (root == nullptr) return 0;
    if (root == p || root == q) ++ flag;
    if (root->left) {
        if (recur236_1(root->left, p, q)) ++ flag;
    }
    if (root->right) {
        if (recur236_1(root->right, p, q)) ++ flag;
    }
    if (flag == 2) {
        if (result == nullptr) result = root;
    }
    return flag;
}

TreeNode *solution236_1(TreeNode *root, TreeNode *p, TreeNode *q) {
    recur236_1(root, p, q);
    return result;
}
