#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        stk.push(val);
        if (mstk.empty() || val <= mstk.top()) {
            mstk.push(val);
        }
    }
    
    void pop() {
        if (mstk.top() == stk.top()) {
            mstk.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mstk.top();
    }
private: 
    stack<int> stk;
    stack<int> mstk;

};