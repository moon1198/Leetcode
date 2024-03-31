#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *tmp1 = headA;
    ListNode *tmp2 = headB;
    bool flag = 0;
    while (tmp1 != tmp2) {
        tmp1 = tmp1 ? tmp1->next : headB;
        tmp2 = tmp2 ? tmp2->next : headA;
    }
    return tmp1;
}