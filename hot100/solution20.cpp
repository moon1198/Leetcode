#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> stk;
    for (char ch : s) {
        if (stk.empty()) {
            stk.push(ch);
        } else {
            switch(ch) {
                case ')' : 
                    if (stk.top() == '(') {
                        stk.pop();
                    } else {
                        stk.push(ch);
                    }
                    break;
                case '}' : 
                    if (stk.top() == '{') {
                        stk.pop();
                    } else {
                        stk.push(ch);
                    }
                    break;
                case ']' : 
                    if (stk.top() == '[') {
                        stk.pop();
                    } else {
                        stk.push(ch);
                    }
                    break;
                default : 
                    stk.push(ch);
                    break;
            }
        }
    }
    return stk.empty();
}