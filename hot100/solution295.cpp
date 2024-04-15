#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (big_heap.size() == less_heap.size()) {
            if (!less_heap.empty() && num > less_heap.top()) {
                big_heap.push(less_heap.top());
                less_heap.pop();
                less_heap.push(num);
            } else 
                big_heap.push(num);
        } else if (less_heap.size() == big_heap.size() - 1){
            if (num >= big_heap.top()) {
                less_heap.push(num);
            } else {
                less_heap.push(big_heap.top());
                big_heap.pop();
                big_heap.push(num);
            }
        } else {
            cout << "add : Can't reach here!" << endl;
        }
    }
    
    double findMedian() {
        if (big_heap.size() == less_heap.size()) {
            return (big_heap.top() + less_heap.top()) / 2.0;
        } else if (less_heap.size() == big_heap.size() - 1){
            return big_heap.top();
        } else {
            cout << "find : Can't reach here!" << endl;
        }
        return -1;
    }

private : 
    priority_queue<int, vector<int>, less<int>> big_heap;
    priority_queue<int, vector<int>, greater<int>> less_heap;
};