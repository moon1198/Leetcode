#include "include.h"


int main() {
    vector<vector<int>> edges = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    vector<int> nums1 = {66,1,28,73,53,35,45,60,100,44,59,94,27,88,7,18,83,18,72,63};
    vector<int> nums2 = {66,20,84,81,56,40,37,82,53,45,43,96,67,27,12,54,98,19,47,77};
    
    vector<int> nums = {824,843,837,620,836,234,276,859};
    //vector<int> nums = {14,9,8,4,3,2};
    int amount = 27;

    //vector<string> wordDict = {"cats","dog","sand","and","cat"};
    vector<string> wordDict = {"apple","pen"};
    vector<vector<int>> grid = {{9,5,7,3},{8,9,6,1},{6,7,14,3},{2,5,3,1}};


    string s = ")()())";
    priority_queue<int, vector<int>, less<int>> que;
    priority_queue<int, vector<int>, greater<int>> qe;


    longestValidParentheses(s);

    return 0;

}