#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution738_0(int n) {
    string strNum = to_string(n);

    int flag = 0;
    for (int i = strNum.size() - 1; i > 0; -- i) {
        if (strNum[i - 1] > strNum[i]) {
            -- strNum[i - 1];
            flag = i;
        }
    }
    for (int i = flag; i < strNum.size(); ++ i) {
        strNum[i] = '9';
    }
    return stoi(strNum);
}