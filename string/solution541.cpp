#include <string>
#include <vector>
#include <utility>

using std::swap;
using std::string;
using std::vector;
string solution541_0(string s, int k) {
    int len = s.size();
    int left = 0, right = 0, front = 0;

    while (len - front >= k) {
        left = front;
        right = left + k - 1;
        while (left < right) {
            swap(s[left], s[right]);
            ++ left;
            -- right;
        }
        front += 2 * k;
    }
    left = front;
    right = len - 1;
    while (left < right) {
        swap(s[left], s[right]);
        ++ left;
        -- right;
    }
    return s;
}