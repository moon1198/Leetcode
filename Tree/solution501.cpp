#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode"

using namespace std;

static TreeNode *pre = nullptr;
static vector<int>vec;
static int count_tmp = 1;
static int count_max = 1;
void recur501_0(TreeNode *root) {
    if (root == nullptr) return;
    recur501_0(root->left);
    if (pre != nullptr) {
        if (pre->val == root->val){
            count_tmp ++;
        }else if(pre->val != root->val){
            if (count_tmp > count_max){
                count_max = count_max;
                vec.clear();
                vec.push_back(pre->val);
            }else if(count_tmp == count_max) {
                vec.push_back(pre->val);
            }
            count_tmp = 1;
        }
    }
    pre = root;
    recur501_0(root->right);
}
vector<int> solution501_0(TreeNode *root) {
    recur501_0(root);
    if (count_tmp > count_max){
        count_max = count_max;
        vec.clear();
        vec.push_back(pre->val);
    }else if(count_tmp == count_max) {
        vec.push_back(pre->val);
    }
    return vec;
}