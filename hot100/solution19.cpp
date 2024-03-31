#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

int traverse(ListNode *head, int n) {
    int cur = 0;
    if (head != NULL) {
        cur = traverse(head->next, n) + 1;
        if (cur == n + 1) {
            ListNode *tmp = head->next;
            head->next = head->next->next;
        }
    } else {
        return 0;
    }
    return cur;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *pre = new ListNode(0, head);
    traverse(pre, n);
    return pre->next;
}