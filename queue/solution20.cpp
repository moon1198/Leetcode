#include <string>
#include <stack>
using std::string;
using std::stack;

bool solution20_0(string s) {
    stack<char> stk;
    for (auto i : s) {
        if (stk.empty()) {
            stk.push(i);
        }else {
            switch (i) {
                case '(':
                case '{':
                case '[': stk.push(i); break;
                case ')': if (stk.top() == '(') stk.pop(); else return false; break;
                case '}': if (stk.top() == '{') stk.pop(); else return false; break;
                case ']': if (stk.top() == '[') stk.pop(); else return false; break;
                default: stk.push(i); break;
            }
        }
    }
    return stk.empty();
}