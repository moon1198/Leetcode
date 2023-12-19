#include <string>
#include <vector>
#include <iostream>
#include "include"
using namespace std;

int main () {
    //vector<int> vec = {1,2,3,4,5,6};
    //vector<TreeNode> tree(vec.size() + 1);
    //int size = tree.size();
    //for (int i = 1; i < size; ++ i) {
    //    tree[i].val = vec[i - 1];
    //    if (2 * i < size) {
    //        tree[i].left = &tree[2 * i];
    //    }else {
    //        tree[i].left = nullptr;
    //    }
    //    if (2 * i + 1 < size) {
    //        tree[i].right = &tree[2 * i + 1];
    //    }else {
    //        tree[i].right = nullptr;
    //    }
    //}
    //TreeNode* root = &tree[1];
    vector<int>pre = {3,9,20,15,7};
    vector<int>in = {9,3,15,20,7};

    TreeNode* root = solution654_0(pre);
    // TreeNode* root = solution105_0(pre, in);
    queue<TreeNode*>que;
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
        TreeNode* tmp = que.front();
        cout << tmp->val << "; ";
        que.pop();
        if (tmp->left) que.push(tmp->left);
        if (tmp->right) que.push(tmp->right);
    }
    cout << endl;
    
    // for (auto i : ans) {
    //    cout << i;
    //    cout << endl;
    // }

    return 0;
}