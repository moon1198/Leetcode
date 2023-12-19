#include <string>
#include <vector>

using std::string;
using std::vector;

bool solution242_0(string s, string t) {
    vector<int> char_table(26);
    for (char ch : s) {
        char_table[ch - 'a'] += 1;
    }
    for (char ch : t) {
        char_table[ch - 'a'] -= 1;
    }
    for (auto val : char_table) {
        if (val != 0) {
            return false;
        }
    }
    return true;
}