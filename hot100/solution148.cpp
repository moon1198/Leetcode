#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

ListNode *merge(ListNode *l1, ListNode *l2) {
    ListNode *tmp1 = l1, *tmp2 = l2, *tmp;
    tmp = new ListNode(0);
    ListNode *ret = tmp;
    while (tmp1 != nullptr && tmp2 != nullptr) {
        if (tmp1->val > tmp2->val) {
            tmp->next = tmp2;
            tmp2 = tmp2->next;
        } else {
            tmp->next = tmp1;
            tmp1 = tmp1->next;
        }
        tmp = tmp->next;
    }
    if (tmp1 != nullptr) {
        tmp->next = tmp1;
    } else if (tmp2 != nullptr) {
        tmp->next = tmp2;
    }
    return ret->next;
}

ListNode *sortList(ListNode *head, ListNode *tail) {
    //空
    if (head == nullptr) {
        return head;
    }
    //一个元素
    if (head->next == tail) {
        //important point
        head->next = nullptr;
        return head;
    }
    ListNode *slow, *fast;
    slow = head; fast = head;
    while (fast != tail && fast->next != tail) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return merge(sortList(head, slow), sortList(slow, tail));
}

ListNode* sortList(ListNode* head) {
    //归并
    return sortList(head, nullptr);
}