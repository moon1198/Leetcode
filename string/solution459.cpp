#include <string>
#include <vector>
using namespace std;
vector<int> get_next2(string needle);
bool solution459_0(string s) {
    vector<int>vec;
    int len = s.size();
    if (len == 0) {
        return false;
    }
    vec = get_next2(s);
    if (vec[len - 1] != 0 &&  len % (len - vec[len - 1]) == 0) {
        return true;
    }
    return false;
}