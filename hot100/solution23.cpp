#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;


ListNode* mergeKLists0(vector<ListNode*>& lists) {
    auto cmp = [](const ListNode *l1, const ListNode *l2) {return l1->val > l2->val;};
    // priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq;
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
    for (auto head : lists) {
        if (head) pq.push(head);
    }
    ListNode *ans = new ListNode(0);
    ListNode *tmp = ans;
    while (!pq.empty()) {
        tmp->next = pq.top();
        tmp = tmp->next;
        pq.pop();
        if (tmp->next) pq.push(tmp->next);
    }
    return ans->next;
}


ListNode *combine(ListNode *l1, ListNode *l2) {
    if (!l1 || !l2) {
        return l1 ? l1 : l2;
    }
    ListNode *ret = new ListNode(0);
    ListNode *tmp = ret;
    while (l1 && l2) {
        if (l1->val > l2->val) {
            tmp->next = l2;
            l2 = l2->next;
        } else {
            tmp->next = l1;
            l1 = l1->next;
        }
        tmp = tmp->next;
    }
    tmp->next = l1 ? l1 : l2;
    return ret->next;
}

ListNode* divide(vector<ListNode *> &lists, int l, int r) {
    if (l == r) {
        return lists[l];
    }
    if (l > r) {
        return nullptr;
    }
    int mid = (l + r) / 2;
    return combine(divide(lists, l, mid), divide(lists, mid + 1, r));
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    return divide(lists, 0, lists.size() - 1);
}