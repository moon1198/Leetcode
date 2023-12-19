#include <iostream>
#include <vector>
#include <string>
#include "include.h"
using namespace std;
int main (){
    vector<int> nums{3,3,3,1,2,1,1,2,3,3,4};
    string s = "ADOBECODEBANC";
    string t = "ABC";
    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    //vector<vector<int>> matrix = {{2,5,8}, {4,0,-1}};
    for (auto b : solution54_1(matrix)){
        cout << b << "; ";
    }
    //for (int &row : nums) {
    //    cout << row << "; ";
    //}
    //cout << endl;
    //cout << "test" << endl;
    return 0;
}