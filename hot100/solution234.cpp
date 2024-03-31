#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

bool isPalindrome0(ListNode* head) {
    stack<int> stk;

    ListNode *tmp = head;
    while (tmp) {
        stk.push(tmp->val);
        tmp = tmp->next;
    }
    tmp = head;
    while (tmp) {
        if (tmp->val != stk.top()) {
            return false;
        }
        stk.pop();
        tmp = tmp->next;
    }
    return true;
}


ListNode *reverse_list(ListNode *head) {
    ListNode *pre = NULL;
    while (head != NULL) {
        ListNode *nxt = head->next;
        head->next = pre;
        pre = head;
        head = nxt;
    }
    return pre;
}

ListNode *mid_loc(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool isPalindrome(ListNode* head) {
    ListNode *mid = mid_loc(head);
    ListNode *tmp1 = head;
    ListNode *tmp2 = reverse_list(mid->next);
    bool ans = true;
    while (ans && tmp2 != NULL) {
        if (tmp1->val != tmp2->val) {
            ans = false;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    reverse_list(mid->next);
    return ans;
}
