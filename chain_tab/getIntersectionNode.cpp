
#include "ListNode"
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = 0, lenB = 0, gap = 0;
    ListNode *l = nullptr, *s = nullptr;
    s = headA;
    while (s){
        ++ lenA;
        s = s->next;
    }
    s = headB;
    while (s) {
        ++ lenB;
        s = s->next;
    }
    if (lenA > lenB) {
        l = headA;
        s = headB;
        gap = lenA - lenB;
    }else{
        l = headB;
        s = headA;
        gap = lenB - lenA;
    }
    while (gap --){l = l->next;}
    while (l != nullptr) {
        if (l == s) {
            return l;
        }else{
            l = l->next;
            s = s->next;
        }
    }
    return l;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *L1 = headA;
    ListNode *L2 = headB;
    while (L1 != L2) {
        L1 = L1 == nullptr ? headB : L1->next;
        L2 = L2 == nullptr ? headA : L2->next;
    }
    return L1;
}