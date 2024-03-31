#ifndef __LISTNODE_H_
#define __LISTNODE_H_

struct ListNode{
    int val;
    ListNode *next;
    ListNode() = default;
    ListNode(int x) : val(x), next(NULL) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};
#endif