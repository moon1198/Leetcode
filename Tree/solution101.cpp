#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include "TreeNode"

using namespace std;

bool recur101(TreeNode* left, TreeNode* right) {
    if (!(left || right)) {
        return true;
    }else if (left && right) {
        if (recur101(left->left, right->right) && recur101(left->right, right->left)) {
            if (left->val == right->val) return true;
        }
    }
    return false;
}
bool recur101_1(TreeNode* left, TreeNode* right) {
    if (!(left || right)) {
        return true;
    }else if (left && right) {
        //在递归过程中，true需要满足的就是此三项的和
        return recur101_1(left->left, right->right) && recur101_1(left->right, right->left) && (left->val == right->val);
    }else {
        return false;
    }
}
bool solution101_0(TreeNode* root) {
    return recur101(root->left, root->right);
}

bool solution101_1(TreeNode* root) { 
    stack<TreeNode*> stk1;
    stack<TreeNode*> stk2;
    if (!(root->left || root->right)) {
        return true;
    }else if (root->left && root->right) {
        TreeNode* cur1 = root->left;
        stk1.push(cur1);
        TreeNode* cur2 = root->right;
        stk2.push(cur2);
        while (!(stk1.empty() || stk2.empty())) {
            cur1 = stk1.top();
            stk1.pop();
            cur2 = stk2.top();
            stk2.pop();
            
            if (cur1->val != cur2->val) return false;

            if (!(cur1->right || cur2->left)) {}
            else if (cur1->right && cur2->left) {
                stk1.push(cur1->right);
                stk2.push(cur2->left);
            }else {
                return false;
            }


            if (!(cur1->left || cur2->right)) {}
            else if (cur1->left && cur2->right){
                stk1.push(cur1->left);
                stk2.push(cur2->right);
            }else {
                return false;
            }
        }
    }else {
        return false;
    }
    return true;
}