#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

//run-out-time 
int solution134_0(vector<int> &gas, vector<int> &cost) {

    for (int i = 0; i < gas.size(); ++ i) {
        int rest = gas[i] - cost[i];
        int index = (i + 1) % gas.size();
        while (index != i && rest >= 0) {
            rest += gas[index] - cost[index];
            index = (index + 1) % gas.size();
        }
        if (index == i && rest >= 0) {
            return i;
        }
    }
    return -1;
}



int solution134_1(vector<int> &gas, vector<int> &cost) {
    int sum = 0;
    int owe = 0;
    int index = 0;
    //if ok, the last segment must been positive and cover the preceding negative segments;
    for (int i = 0; i < gas.size(); ++ i) {
        sum += gas[i] - cost[i];
        if (sum < 0) {
            index = i + 1;
            owe += sum;
            sum = 0;
        }
    }
    if (sum + owe >= 0) {
        return index;
    }
    return -1;
}