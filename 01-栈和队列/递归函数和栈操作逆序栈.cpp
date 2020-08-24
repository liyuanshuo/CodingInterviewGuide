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
    int getAndRemoveLastElement(stack<int> &dataStack) {
        int result = dataStack.top();
        dataStack.pop();
        if (dataStack.empty()) {
            return result;
        } else {
            int last = getAndRemoveLastElement(dataStack);
            dataStack.push(result);
            return last;
        }
    }

public:
    void reverse(stack<int> &dataStack) {
        if (dataStack.empty()) {
            return;
        }
        int last = getAndRemoveLastElement(dataStack);
        reverse(dataStack);
        dataStack.push(last);
    }
};
