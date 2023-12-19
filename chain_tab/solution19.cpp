#include "ListNode"

int recur19(ListNode *pre, int n){
    int count = 0;
    ListNode *cur = pre->next;
    //终止条件
    if (cur->next){
        count = recur19(cur, n);
    }
    //返回过程
    count ++;
    if (count == n){
        pre->next = cur->next;
    }
    return count;
}
ListNode *solution19_0(ListNode *head, int n){
    ListNode *pre = new ListNode(0);
    if (head == nullptr){
        return head;
    }
    pre->next = head;
    recur19(pre, n);
    return pre->next;
}