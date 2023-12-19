#include <vector>
#include <string>
#include <stack>

using std::vector;
using std::stack;
using std::string;

int solution150_0(vector<string>& tokens) {
    stack<int> stk;
    int op1, op2;
    for (auto i : tokens) {
        if (i == "+" || i == "-" || i == "*" || i == "/") {
            op2 = stk.top();
            stk.pop();
            op1 = stk.top();
            stk.pop();
            if (i == "+") {stk.push(op1 + op2); continue;}
            if (i == "-") {stk.push(op1 - op2); continue;}
            if (i == "*") {stk.push(op1 * op2); continue;}
            if (i == "/") {stk.push(op1 / op2); continue;}
        }else {
            stk.push(stoi(i));
        }
    }
    return stk.top();
}