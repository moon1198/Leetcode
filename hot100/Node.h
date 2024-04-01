#ifndef __NODE_H_
#define __NODE_H_
class Node {

public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


#endif