#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
    stack<int> dataStack;
    stack<int> minStack;

public:
    void push(int num) {
        if (minStack.empty()) {
            minStack.push(num);
        } else if (getMin() > num) {
            minStack.push(num);
        } else {
            int minNum = minStack.top();
            minStack.push(minNum);
        }
        dataStack.push(num);
    }

    int pop() {
        if (dataStack.empty()) {
            return INT_MIN;
        }
        minStack.pop();
        int num = dataStack.top();
        dataStack.pop();
        return num;
    }

    int getMin() {
        if (minStack.empty()) {
            return INT_MIN;
        }
        return minStack.top();
    }
};