#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode"

using namespace std;

TreeNode* solution226_0(TreeNode* root) {
    //层序
    TreeNode* cur = root;
    queue<TreeNode*> que;
    if (cur != nullptr) que.push(cur);
    while (!que.empty()) {
        cur = que.front();
        swap(cur->left, cur->right); 
        que.pop();
        if (cur->left) que.push(cur->left);
        if (cur->right) que.push(cur->right);
    }
    return root;
}

void recur226(TreeNode* cur) {
    //中序时，先进入左节点，左右节点互换，这时未处理的右节点已变成了左节点；
    if (cur == nullptr) return ;
    swap(cur->left, cur->right);
    recur226(cur->left);
    recur226(cur->right);
}
TreeNode* solution226_1(TreeNode* root) {
    //前序
    recur226(root);
    return root;
}