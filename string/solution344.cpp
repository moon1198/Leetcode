#include <string>
#include <vector>

using std::string;
using std::vector;
void solution344_0(vector<char> &s) {
    size_t len = s.size();
    int left = 0, right = len - 1;
    char ch;
    while (left < right) {
        ch = s[right];
        s[right] = s[left];
        s[left] = ch;
        ++ left;
        -- right;
    }
}