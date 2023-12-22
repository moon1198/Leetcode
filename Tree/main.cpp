#include <string>
#include <vector>
#include <iostream>
#include "include"
using namespace std;

int main () {
    //init a tree
    vector<int> vec = {6,2,8,0,4,7,9};
    vector<TreeNode> tree(vec.size() + 1);
    int size = tree.size();
    for (int i = 1; i < size; ++ i) {
       tree[i].val = vec[i - 1];
       if (2 * i < size) {
           tree[i].left = &tree[2 * i];
       }else {
           tree[i].left = nullptr;
       }
       if (2 * i + 1 < size) {
           tree[i].right = &tree[2 * i + 1];
       }else {
           tree[i].right = nullptr;
       }
    }
    TreeNode* root = &tree[1];

    //operate 

    solution235_0(root, &tree[2], &tree[5]);
    //queue<TreeNode*>que;
    //if (root != nullptr) que.push(root);
    //while (!que.empty()) {
    //    TreeNode* tmp = que.front();
    //    cout << tmp->val << "; ";
    //    que.pop();
    //    if (tmp->left) que.push(tmp->left);
    //    if (tmp->right) que.push(tmp->right);
    //}
    //cout << endl;
    
    // for (auto i : ans) {
    //    cout << i;
    //    cout << endl;
    // }

    return 0;
}