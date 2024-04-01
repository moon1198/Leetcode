#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

//左侧最深，加右侧最深，为该节点值
int postorder(TreeNode *root, int &maxdia) {
    if (root == nullptr) {
        return 0;
    }
    int left = postorder(root->left, maxdia) + 1;
    int right = postorder(root->right, maxdia) + 1;

    maxdia = max(maxdia, left + right);
    return max(left, right);
}

int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0;
    postorder(root, ans);
    //ans原为路径节点数,需转换为边数
    return ans - 2;
}