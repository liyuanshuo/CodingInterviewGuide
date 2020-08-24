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
public:
    void sortStack(stack<int>& data) {
        stack<int> help;
        while (!data.empty()) {
            int cur = data.top();
            data.pop();
            while (!help.empty() && help.top() < cur) {
                data.push(help.top());
                help.pop();
            }
            help.push(cur);
        }
        while (!help.empty()) {
            data.push(help.top());
            help.pop();
        }
    }
};

int main() { return 0; }