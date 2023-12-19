#include "ListNode"

ListNode *solution24_0(ListNode *head){
    ListNode *cur = head;
    ListNode *pre = new ListNode(0);
    pre->next = head;
    ListNode *nxt;
    if (head && head->next){
        head = head->next;
    }
    while (cur != nullptr && cur->next != nullptr){
        pre->next = cur->next;
        nxt = cur->next->next;
        cur->next->next = cur;
        cur->next = nxt;

        pre = cur;
        cur = nxt;
    }
    return head;
}