#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    bool flag = false;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            flag = true;
            slow = head;
            break;
        }
    }
    if (flag) {
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    return NULL;
}