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

class Soulution {
private:
    stack<int> pushStack;
    stack<int> popStack;

    void pushToPop() {
        if (popStack.empty()) {
            while (!pushStack.empty()) {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
        }
    }

public:
    void add(int num) {
        pushStack.push(num);
        pushToPop();
    }

    int poll() {
        if (popStack.empty() && pushStack.empty()) {
            return INT_MIN;
        }
        pushToPop();
        int num = popStack.top();
        popStack.pop();
        return num;
    }

    int peek() {
        if (pushStack.empty() && popStack.empty()) {
            return INT_MIN;
        }
        pushToPop();
        return popStack.top();
    }
};