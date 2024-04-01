#include <bits/stdc++.h>
#include "Node.h"
using namespace std;

Node* copyRandomList0(Node* head) {
    unordered_map<Node *, Node *> mp;
    Node *cur = head;
    Node *head1 = new Node(0);
    Node *pre = head1;
    Node *cur1;
    while (cur != NULL) {
        cur1 = new Node(cur->val);
        pre->next = cur1;
        mp[cur] = cur1;

        pre = cur1;
        cur = cur->next;
    }

    cur = head;
    cur1 = head1->next;
    while (cur != NULL) {
        cur1->random = mp[cur->random];

        cur1 = cur1->next;
        cur = cur->next;
    }

    return head1->next;
}

Node* copyRandomList(Node* head) {
    //合并
    if (head == NULL) return head;
    Node *cur = head;
    while (cur != NULL) {
        Node *nxt = cur->next;
        Node *tmp = new Node(cur->val);
        cur->next = tmp;
        tmp->next = nxt;
        cur = nxt;
    }

    //指向和拆分不可在同一步实现，后面元素可指向前面已处理元素
    //random 指向
    cur = head;
    Node *ans = head->next;
    while (cur != NULL) {
        cur->next->random = cur->random ? cur->random->next : cur->random;
        cur = cur->next->next;
    }

    //拆分
    cur = head;
    while (cur != NULL) {
        Node *tmp = cur->next;
        cur->next = cur->next->next;
        if (cur->next) 
            tmp->next = tmp->next->next;
        cur = cur->next;
    }
    return ans; 
}

