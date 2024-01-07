#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

bool solution860_0(vector<int> &bills) {
    map<int, int>mp;
    mp[5] = 0; mp[10] = 0; mp[20] = 0;

    for (int it : bills) {
        ++ mp[it];
        int charge = it - 5;
        int sum = 0;
        int i = 0, j = 0, k = 0;
        for (i = 0; i < mp[20]; ++ i) {
            if (sum + 20 > charge) {
                break;
            }
            sum += 20;
        }
        for (j = 0; j < mp[10]; ++ j) {
            if (sum + 10 > charge) {
                break;
            }
            sum += 10;
        }
        for (k = 0; k < mp[5]; ++ k) {
            if (sum + 5 > charge) {
                break;
            }
            sum += 5;
        }
        if (sum != charge) return false;
        mp[20] -= i; mp[10] -= j; mp[5] -= k;
    }
    return true;
}

bool solution860_1(vector<int> &bills) {
    int five = 0, ten = 0, twenty = 0;
    for (auto it : bills) {
        switch (it) {
            case 5: ++ five; break;
            case 10: if (five <= 0) return false;
                else {
                    -- five; 
                    ++ ten;
                    break;
                }
            case 20:
                if (five >= 0 && ten >= 0) {
                    -- five; -- ten;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
                ++ twenty;
                break;
            default: break;
        }
    }
    return true;
}