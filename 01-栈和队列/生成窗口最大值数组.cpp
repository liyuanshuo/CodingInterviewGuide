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
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {

public:
    vector<int> getMaxWindow(vector<int>& arr, int w) {
        vector<int> ans;
        if (arr.size() < 1) {
            return ans;
        }
        deque<int> qmax;
        for (int i = 0; i < arr.size(); ++i) {
            while (!qmax.empty() && qmax.back() <= arr[i]) {
                qmax.pop_back();
            }
            qmax.push_back(i);
            if (qmax.front() == i - w) {
                qmax.pop_front();
            }
            if (i >= w - 1) {
                ans.push_back(arr[qmax.front()]);
            }
        }
        return ans;
    }
};