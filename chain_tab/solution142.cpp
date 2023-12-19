#include "ListNode"
ListNode *solution142_0(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    bool flag = false;
    while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast){
            flag = true;
            slow = head;
            break;
        }
    }
    if (flag){
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }else{
        return nullptr;
    }
    return slow;
}