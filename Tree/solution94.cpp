#include <vector>
#include <stack>
using namespace std;
#include "TreeNode"
void traversal94(TreeNode *cur, vector<int> &vec) {
    if (cur == nullptr) {
        return ;
    }
    traversal94(cur->left, vec);
    vec.push_back(cur->val);
    traversal94(cur->right, vec);
}
vector<int> solution94_0(TreeNode *root) {
    vector<int> vec;
    traversal94(root, vec);
    return vec;
}

//迭代求解
vector<int> solution94_1(TreeNode *root) {
    vector<int> vec;
    stack<TreeNode*>stk;
    TreeNode *cur = root;
    TreeNode *tmp;
    while (cur != nullptr) {
        stk.push(cur);
        cur = cur->left;
    }
    while (!stk.empty()) {
        tmp = stk.top();
        vec.push_back(tmp->val);
        stk.pop();
        if (tmp->right) {
            cur = tmp->right;
            while (cur != nullptr) {
                stk.push(cur);
                cur = cur->left;
            }
        }
    }
    return vec;
}
//迭代求解
vector<int> solution94_2(TreeNode *root) {
    vector<int> vec;
    stack<TreeNode*>stk;
    TreeNode *cur = root;
    while (cur != nullptr || !stk.empty()) {
        if (cur != nullptr) {
            stk.push(cur);
            cur = cur->left;
        }else {
            cur = stk.top();
            stk.pop();
            vec.push_back(cur->val);
            cur = cur->right;
        }
    }
    return vec;
}
//统一迭代格式
vector<int> solution94_3(TreeNode *root) { 
    stack<TreeNode*>stk;
    TreeNode *cur = root;
    vector<int>vec;
    if (cur == nullptr) return vec;
    stk.push(cur);
    while (!stk.empty()) {
        cur = stk.top();
        if(cur) {
            stk.pop();
            if (cur->right) stk.push(cur->right);
            stk.push(cur);
            stk.push(nullptr);
            if (cur->left) stk.push(cur->left);
        }else {
            stk.pop();
            cur = stk.top();
            vec.push_back(cur->val);
            stk.pop();
        }
    }
    return vec;
}