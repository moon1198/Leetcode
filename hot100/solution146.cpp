#include <bits/stdc++.h>
#include "ListNode.h"

using namespace std;

class Node{
public:
    int key, val;
    Node *prev; 
    Node *next;
    Node(int x, int y) : key(x), val(y) {
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
        cur_capacity = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        Node *tmp = mp[key];
        //断开， 删去
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;

        //建立连接
        tmp->next = head->next;
        tmp->prev = head;

        head->next = tmp;
        tmp->next->prev = tmp;
        return tmp->val;
    }
    
    void put(int key, int value) {
        if (get(key) != -1) {
            mp[key]->val = value;
            return ;
        }
        //先删后加入，避免加入和删除的key相同造成错误
        if (cur_capacity >= m_capacity) {
            Node *tmp = tail->prev;
            tail->prev = tmp->prev;
            tmp->prev->next = tail;
            mp.erase(tmp->key);
            delete tmp;
            -- cur_capacity;
        }

        Node *tmp = new Node(key, value);
        Node *nxt = head->next;
        head->next = tmp;
        tmp->prev = head;
        tmp->next = nxt;
        nxt->prev = tmp;
        ++ cur_capacity;
        mp[key] = tmp;
    }
private:
    Node *head;
    Node *tail;

    int m_capacity;
    int cur_capacity;
    unordered_map<int, Node*> mp;
};