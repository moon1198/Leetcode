#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include "TreeNode"

using namespace std;

bool recur100_0 (TreeNode* p, TreeNode* q){
    if (!(p || q)) {
        return true;
    }else if (q && p) {
        if (p->val == q->val) {
            return recur100_0(p->left, q->left) && recur100_0(p->right, q->right);
        }else {
            return false;
        }
    }else {
        return false;
    }
}

bool recur100_1 (TreeNode* p, TreeNode* q){
    if (!(p || q)) {
        return true;
    }else if (q && p) {
        if (recur100_1(p->left, q->left) && recur100_1(p->right, q->right)) {
            return p->val == q->val;
        }
    }
    return false;
}

bool solution100_0(TreeNode* p, TreeNode* q) {
    return recur100_0(p, q);
}



bool solution100_1(TreeNode* p, TreeNode* q) {
    stack<TreeNode*>stk1;
    stack<TreeNode*>stk2;
    stk1.push(p);
    stk2.push(q);

    while (!(stk1.empty() || stk2.empty())) {
        TreeNode* cur1 = stk1.top();
        stk1.pop();
        TreeNode* cur2 = stk2.top();
        stk2.pop();

        if (!(cur1 || cur2)) {}
        else if (cur1 && cur2) {
            if (cur1->val == cur2->val) {
                if (!(cur1->left || cur2->left)) {}
                else if  (cur1->left && cur2->left){
                    stk1.push(cur1->left);
                    stk2.push(cur2->left);
                }else {
                    return false;
                }

                if (!(cur1->right || cur2->right)) {}
                else if  (cur1->right && cur2->right){
                    stk1.push(cur1->right);
                    stk2.push(cur2->right);
                }else {
                    return false;
                }
            }else {
                return false;
            }
        }else {
            return false;
        }
    }
    return true;
}

bool solution100_2(TreeNode* p, TreeNode* q) {
    stack<TreeNode*>stk1;
    stack<TreeNode*>stk2;
    if (p && q) {
        stk1.push(p);
        stk2.push(q);
    }else if(!(q || p)) {
        return true;
    }else {
        return false;
    }

    while (!(stk1.empty() || stk2.empty())) {
        TreeNode* cur1 = stk1.top();
        stk1.pop();
        TreeNode* cur2 = stk2.top();
        stk2.pop();

        if (cur1->val != cur2->val) {
            return false;
        }

        if (!(cur1->left || cur2->left)) {}
        else if  (cur1->left && cur2->left){
            stk1.push(cur1->left);
            stk2.push(cur2->left);
        }else {
            return false;
        }

        if (!(cur1->right || cur2->right)) {}
        else if  (cur1->right && cur2->right){
            stk1.push(cur1->right);
            stk2.push(cur2->right);
        }else {
            return false;
        }
    }

    return true;
}