#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

vector<vector<int>> solution406_0(vector<vector<int>> &people) {
    //ingore all the ones shorter than me 
    //select the true position from the space queue; 
    vector<vector<int>> ans(people.size(), vector<int> (2, -1));
    sort(people.begin(), people.end(), [] (vector<int> &s1, vector<int> &s2) {return s1[0] < s2[0] || (s1[0] == s2[0] && s1[1] > s2[1]); });
    for (int i = 0; i < people.size(); ++ i) {
        int index = -1;
        for (int j = 0; j < ans.size(); ++ j) {
            if (ans[j][0] == -1) {
                ++ index;
            }
            if (index == people[i][1]) {
                ans[j] = people[i];
                break;
            }
        }
    }
    return ans;
}