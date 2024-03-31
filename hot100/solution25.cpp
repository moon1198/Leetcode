#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

void reverse_lst(ListNode *begin) {
    ListNode *pre, *cur, *nxt;
    pre = NULL; cur = begin;
    while (cur != nullptr) {

        nxt = cur->next;
        cur->next = pre;

        pre = cur;
        cur = nxt;
    }
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *ans = new ListNode(0, head);
    ListNode *end = ans, *pre = ans;

    while (end != nullptr) {
        for (int i = 0; i < k && end != NULL; ++ i) {
            end = end->next;
        }
        if (end == NULL) break;

        ListNode *begin = pre->next;
        ListNode *nxt = end->next;
        end->next = nullptr;

        pre->next = end;
        reverse_lst(begin);
        pre = begin;
        pre->next = nxt;
        end = pre;

    }
    return ans->next;
}