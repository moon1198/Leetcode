#include <vector>
#include <queue>
#include <algorithm>
#include "Node1"

using namespace std;

//层序遍历
int solution559_0(Node* root) {
    queue<Node*>que;
    int count = 0;
    if (root != nullptr) que.push(root);
    while (!que.empty()) {
        int size = que.size(); 
        for (int i = 0; i < size; ++ i) {
            Node* cur = que.front();
            que.pop();
            int child_count = cur->children.size();
            for (int j = 0; j < child_count; ++ j) {
                que.push(cur->children[j]);
            }
        }
        count ++;
    }
    return count;
}

//递归
int recur559_0(Node* root) {
    if (root == nullptr) return 0;
    int count = root->children.size();
    int ans = 0;
    //此处出现错误，ret返回子节点高度，ret ++表示当前节点高度，但内嵌于for循环中，在叶节点处
    //无法进入for循环，少了一次加一，所以结果总是少一
    //应将for循环只作为最高子树筛选，而不包括其他
    //for (int i = 0; i < count; ++ i) {
    //    int ret = recur559_0(root->children[i]);
    //    ret ++;
    //    ans = ans > ret ? ans : ret;
    //}
    //return ans;

    for (int i = 0; i < count; ++ i) {
        int ret = recur559_0(root->children[i]);
        ans = ans > ret ? ans : ret;
    }
    return ans + 1;
}

int solution559_1(Node* root) {
    return recur559_0(root);
}
 

int recur559_1(Node* root, int depth) {
    if (root->children.size() == 0) return depth;
    int ans = 0;
    int child_count = root->children.size();
    for (int i = 0; i < child_count; ++ i) {
        int ret = recur559_1(root->children[i], depth + 1);
        ans = ans > ret ? ans : ret;
    }
    return ans;
}
int solution559_2(Node* root) {
    if (root == nullptr) return 0;
    return recur559_1(root, 1);
}