#ifndef __TREENODE_H_
#define __TREENODE_H_

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r){}
};

#endif