#include <vector>
#include <queue>
#include <algorithm>
#include "Node2"

using namespace std;

Node* solution116_0(Node* root) {
    Node* cur = root;
    queue<Node*> que;
    if (cur != nullptr) que.push(cur);
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size - 1; ++ i) {
            cur = que.front();
            que.pop();
            cur->next = que.front();
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
        }
        cur = que.front();
        //next has been set to nullptr by default
        que.pop();
        if (cur->left) que.push(cur->left);
        if (cur->right) que.push(cur->right);
    }
    return root;
}