#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *head = new ListNode;
    ListNode *cur = head;

    int flag = 0;
    while (l1 || l2 || flag) {
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        int sum = n1 + n2 + flag;
        flag = sum / 10;

        ListNode *tmp = new ListNode(sum % 10);
        cur->next = tmp;
        cur = tmp;

        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }
    return head->next;
}