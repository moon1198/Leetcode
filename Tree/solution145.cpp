#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

#include "TreeNode"
void traversal145(TreeNode *cur, vector<int> &vec) {
    if (cur == nullptr) {
        return ;
    }
    traversal145(cur->left, vec);
    traversal145(cur->right, vec);
    vec.push_back(cur->val);
}
vector<int> solution145_0(TreeNode *root) {
    vector<int> vec;
    traversal145(root, vec);
    return vec;
}

//迭代求解
vector<int> solution145_1(TreeNode *root) {
    stack<TreeNode*> stk;
    vector<int> vec;
    TreeNode *cur = root;
    if (cur == nullptr) return vec;
    stk.push(cur);
    while (!stk.empty()) {
        cur = stk.top();
        vec.push_back(cur->val);
        stk.pop();
        if (cur->left) stk.push(cur->left);
        if (cur->right) stk.push(cur->right);
    }
    reverse(vec.begin(), vec.end());
    return vec;
}
//统一迭代格式
vector<int> solution145_3(TreeNode *root) { 
    stack<TreeNode*>stk;
    TreeNode *cur = root;
    vector<int>vec;
    if (cur == nullptr) return vec;
    stk.push(cur);
    while (!stk.empty()) {
        cur = stk.top();
        if(cur) {
            stk.pop();
            stk.push(cur);
            stk.push(nullptr);
            if (cur->right) stk.push(cur->right);
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