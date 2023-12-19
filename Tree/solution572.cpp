#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include "TreeNode"

using namespace std;

//判断子树是否相等
bool recur572_1 (TreeNode* p, TreeNode* q){
    if (!(p || q)) {
        return true;
    }else if (q && p) {
        if (recur572_1(p->left, q->left) && recur572_1(p->right, q->right)) {
            return p->val == q->val;
        }
    }
    return false;
}

//前序遍历root
bool recur572_0(TreeNode* root, TreeNode* subRoot) {
    if (root == nullptr) {
        return false;
    }
    if (recur572_1(root, subRoot)) return true;
    return recur572_0(root->left, subRoot) || recur572_0(root->right, subRoot);
} 
bool solution572_0(TreeNode* root, TreeNode* subRoot) {
    return recur572_0(root, subRoot);
}