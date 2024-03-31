#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode *pre, *mid, *nxt;
    ListNode *ans = new ListNode(0, head);

    pre = ans; mid = pre->next;

    while (mid != nullptr && mid->next != nullptr) {
        nxt = mid->next;

        pre->next = nxt;
        mid->next = nxt->next;
        nxt->next = mid;

        pre = mid;
        mid = pre->next;
    }
    return ans->next;

}