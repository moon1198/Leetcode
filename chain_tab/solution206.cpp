#include "ListNode"
ListNode* solution206_0(ListNode* head) {
    ListNode* cur = head;
    ListNode* pre = nullptr;
    ListNode* tmp = nullptr;
    while (cur != nullptr) {
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return head;
}

