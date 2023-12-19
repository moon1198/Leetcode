#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include "TreeNode"

using namespace std;

//static vector<TreeNode> ans;
TreeNode* recur106_0(vector<int>& inorder, vector<int>& postorder) {
    int root_val = postorder.back();
    TreeNode* left = nullptr, *right = nullptr;
    
    int len = inorder.size();
    if (len == 1) {
        return new TreeNode(root_val, left, right);
        // ans.emplace_back(root_val, left, right);
        // return &ans.back();
    }

    int i = 0;
    for (i = 0; i < len; ++ i) {
        if (inorder[i] == root_val) break;
    }
    vector<int> left_in(inorder.begin(), inorder.begin() + i);
    vector<int> right_in(inorder.begin() + i + 1, inorder.end());
    // inorder.begin() + i + 1, inorder.end();
    // if (inorder.size() == 1) {
    //     right_in.insert(right_in.end(), left_in.begin(), left_in.end());
    // }else {
    //     right_in.insert(right_in.end(), inorder.begin() + i + 1, inorder.end());
    // }

    vector<int> left_post(postorder.begin(), postorder.begin() + i);
    vector<int> right_post(postorder.begin() + i, postorder.end() - 1);
    // if (postorder.size() == 1) {
    //     right_post.insert(right_post.end(), left_post.begin(), left_post.end());
    // }else {
    //     right_post.insert(right_post.end(), postorder.begin() + i, postorder.end() - 1);
    // }

    if (left_in.size()) left = recur106_0(left_in, left_post);
    if (right_in.size()) right = recur106_0(right_in, right_post);

    return new TreeNode(root_val, left, right);

    // ans.emplace_back(root_val, left, right);
    // return &ans[ans.size() - 1];
}
TreeNode* solution106_0(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty()) return nullptr;
    TreeNode* root = recur106_0(inorder, postorder);
    return root;
    // return &ans.front();
}

//左闭右开
TreeNode* recur106_1(vector<int>& inorder, int in_bg, int in_ed, vector<int>& postorder, int post_bg, int post_ed) {
    int root_val = postorder[post_ed - 1];
    TreeNode* left = nullptr, *right = nullptr;

    int len = in_ed - in_bg;
    if (len == 1) {
        return new TreeNode(root_val, left, right);
    }

    int i = 0;
    for (i = 0; i < len; ++ i) {
        if (inorder[in_bg + i] == root_val) break;
    }

    cout << "---------------------------" << endl;
    cout << "in" << endl;
    cout << in_bg << "   " << in_bg + i << "-----" << in_bg + i + 1 << "   " << in_ed << endl;
    cout << "post" << endl;
    cout << post_bg << "   " << post_bg + i << "-----" << post_bg + i << "   " << post_ed - 1 << endl;
    if (i) left = recur106_1(inorder, in_bg, in_bg + i, postorder, post_bg, post_bg + i);
    if (in_ed - in_bg - i - 1) right = recur106_1(inorder, in_bg + i + 1, in_ed, postorder, post_bg + i, post_ed - 1);

    return new TreeNode(root_val, left, right);

}
TreeNode* solution106_1(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty()) return nullptr;
    TreeNode* root = recur106_1(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    return root;
}