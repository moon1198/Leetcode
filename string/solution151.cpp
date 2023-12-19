#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <iostream>

using namespace std;

string solution151_0(string s) {
    string word;
    string ans;
    vector<string> str_stack;
    istringstream stream(s);
    while(stream >> word) {
        str_stack.push_back(word);
    }
    int len = str_stack.size();
    for (int i = len - 1; i >= 0; -- i) {
        if (i != 0) {
            ans += str_stack[i];
            ans += " ";
        } else {
            ans += str_stack[i];
        }
    }
    return ans;
}
string solution151_1(string s) {
    int slow = 0, fast = 0;
    int len = s.size();
    while (fast < len && s[fast] == ' ') {
        fast ++;
    }
    for (; fast < len; ++ fast) {
        if (fast - 1 > 0 && s[fast] == s[fast - 1] && s[fast] == ' ') {
            continue;
        }else {
            s[slow ++] = s[fast];
        }
    }
    if (slow > 0 && s[slow - 1] == ' ') {
        s.resize(slow - 1);
    }else {
        s.resize(slow);
    }
    len = s.size();
    fast = len - 1;
    slow = 0;
    //reserve all
    while (fast > slow) {
        swap(s[fast], s[slow]);
        fast --; slow ++;
    }
    //reserve words
    int left = 0, right = 0;
    for (fast = 0; fast < len; ++ fast) {
        if (s[fast] == ' ') {
            right = fast - 1;
            while(right > left) {
                swap(s[left], s[right]);
                left ++; right --;
            }
            left = fast + 1;
        }
    }
    //output the last one word
    right = len - 1;
    while(right > left) {
        swap(s[left], s[right]);
        left ++; right --;
    }
    return s;
}