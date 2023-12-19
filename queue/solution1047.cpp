#include <stack>
#include <string>

using std::string;
using std::stack;

string solution1047_0(string s) {
    stack<int> stk;
    for (auto i : s) {
        if (stk.empty() || stk.top() != i) {
            stk.push(i);
        }else {
            stk.pop();
        }
    }
    string ans(stk.size(), ' ');
    for (int i = stk.size(); i != 0; -- i) {
        ans[i - 1] = stk.top();
        stk.pop();
    }
    return ans;
}
string solution1047_1(string s) {
    string ans;
    for (auto i : s) {
        if (ans.empty() || ans.back() != i) {
            ans.push_back(i);
        }else {
            ans.pop_back();
        }
    }
    return ans;
}