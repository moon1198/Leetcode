#include <bits/stdc++.h>
using namespace std;

class Trie {
private:
    Trie *searchNode(string word) {
        Trie *node = this;
        for (auto ch : word) {
            ch = ch - 'a';
            if (node->children[ch] == nullptr) {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }
public:
    //26叉树
    Trie() : children(26), isEnd(false) {
    }
    
    void insert(string word) {
        Trie *node = this;
        for (char ch : word) {
            ch = ch - 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie *node = searchNode(word);
        if (node && node->isEnd) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        if (searchNode(prefix)) return true;
        return false;
    }
private:
    vector<Trie *> children;
    bool isEnd;
};