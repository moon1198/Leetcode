#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

ListNode* reverseList(ListNode* head) {
    ListNode *pre = NULL;
    ListNode *nxt = NULL;
    while (head != NULL) {
        nxt = head->next;
        head->next = pre; 
        pre = head;
        head = nxt;
    }
    return pre;
}