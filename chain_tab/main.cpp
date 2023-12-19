#include <iostream>
#include <string>
#include "solution"
using namespace std;

void display (ListNode* head){
    while (head != nullptr){
        std::cout << head->val; 
        head = head->next;
    }
    std::cout << std::endl;
}

int main(){
    chain_tab solution;
    ListNode arr[5];
    ListNode *head = &arr[0];
    for (int i = 0; i < 5; ++ i){
        arr[i].val = i + 5;
        if (i == 4){
            arr[i].next = nullptr;
        }else{
            arr[i].next = &arr[i + 1];
        }
    }
    ListNode arr1[10];
    ListNode *head1 = &arr1[0];
    for (int i = 0; i < 10; ++ i){
        arr1[i].val = i;
        if (i == 9){
            arr1[i].next = nullptr;
        }else{
            arr1[i].next = &arr1[i + 1];
        }
    }
    display(head);
    display(head1);
    //cout << getIntersectionNode(head1, head)->val << endl;

    //display(head);
    //head = solution19_0(head, 6);
    //display(head);
    // MyLinkedList a;
    // //["MyLinkedList","addAtHead","addAtIndex","get","addAtHead","addAtTail","get","addAtTail","get","addAtHead","get","addAtHead"]
    // //[[],[5],[1,2],[1],[6],[2],[3],[1],[5],[2],[2],[6]]
    // a.addAtHead(5);
    // a.addAtIndex(1, 2);
    // cout << "a[1] = " << a.get(1) << endl;
    // a.addAtHead(6);
    // a.addAtTail(2);
    // cout << "a[3] = " << a.get(3) << endl;
    // a.addAtTail(1);
    // a.display();
    // cout << "a[5] = " << a.get(5) << endl;
    // a.addAtHead(2);
    // cout << "a[2] = " << a.get(2) << endl;
    // a.addAtHead(6);


    // a.display();
}