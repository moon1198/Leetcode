#include <vector>
#include <stack>
using namespace std;
#include "TreeNode"
//前序遍历
void traversal144(TreeNode *cur, vector<int> &vec) {
    if (cur == nullptr) {
        return ;
    }
    vec.push_back(cur->val);
    traversal144(cur->left, vec);
    traversal144(cur->right, vec);
}
vector<int> solution144_0(TreeNode *root) {
    vector<int> vec;
    traversal144(root, vec);
    return vec;
}
//迭代
vector<int> solution144_1(TreeNode *root) {
    vector<int> vec;
    stack<TreeNode*>stk;
    TreeNode *cur = root;
    while (cur != nullptr) {
        vec.push_back(cur->val);
        stk.push(cur);
        cur = cur->left;
    }
    while (!stk.empty()) {
        cur = stk.top();
        stk.pop();
        if (cur->right) {
            vec.push_back(cur->right->val);
            stk.push(cur->right);
            cur = cur->right->left;
            while (cur != nullptr) {
                vec.push_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            }
        }
    }
    return vec;
}
vector<int> solution144_2(TreeNode *root) {
    stack<TreeNode*>stk;
    vector<int>vec;
    TreeNode *cur = root;
    if (cur == nullptr) return vec;
    stk.push(cur);
    while (!stk.empty()) {
        cur = stk.top();
        vec.push_back(cur->val);
        stk.pop();
        if (cur->right) stk.push(cur->right);
        if (cur->left) stk.push(cur->left);
    }
    return vec;
}
//统一迭代格式
vector<int> solution144_3(TreeNode *root) { 
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
            if (cur->left) stk.push(cur->left);
            stk.push(cur);
            stk.push(nullptr);
        }else {
            stk.pop();
            cur = stk.top();
            vec.push_back(cur->val);
            stk.pop();
        }
    }
    return vec;
}
