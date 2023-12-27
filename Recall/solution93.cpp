#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

static vector<string> res;
static string tmp;

// void recur93_0(string s, int index, int level) {
//     if (index >= static_cast<int>(s.size()) || level == 4) {
//         if (level == 4) {
//             res.push_back(tmp);
//         }
//         return ;
//     }
//     for (int i = index; i < static_cast<int>(s.size()); ++ i) {
//         string slice(s.begin() + index, s.begin() + i + 1);
//         //how to modify type<string>
//         //note the length of slice, out of range, 
//         if (slice[0] - '0' != 0 && stoi(slice) >= 0 && stoi(slice) <= 255) {
//             tmp.insert(tmp.end(), slice.begin(), slice.end());
//             if (level < 3) tmp += ".";
//             recur93_0(s, i + 1, level + 1);
//             if (level < 3) tmp.pop_back();
//             tmp.erase(tmp.end() - slice.size(), tmp.end());
//         }else{
//             continue;
//         }
//     }
// }
void recur93_0(string s, int index, int level) {
    if (index >= static_cast<int>(s.size()) || level >= 4) {
        if (level == 4 && index && index >= static_cast<int>(s.size())) {
            res.push_back(tmp);
        }
        return ;
    }
    for (int i = index; i < static_cast<int>(s.size()); ++ i) {
        string slice(s.begin() + index, s.begin() + i + 1);
        //how to modify type<string>
        //note the length of slice, out of range, 
        if ((slice[0] - '0' != 0 && slice.size() < 4 && stoi(slice) >= 0 && stoi(slice) <= 255) || (slice[0] - '0' == 0 && slice.size() == 1)) {
            tmp.insert(tmp.end(), slice.begin(), slice.end());
            if (level < 3) tmp += ".";
            recur93_0(s, i + 1, level + 1);
            if (level < 3) tmp.pop_back();
            tmp.erase(tmp.end() - slice.size(), tmp.end());
        }else{
            continue;
        }
    }
}
vector<string> solution93_0(string s) {
    recur93_0(s, 0, 0);
    return res;
}