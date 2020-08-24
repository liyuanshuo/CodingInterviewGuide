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
    vector<vector<int>> getNearLessNoRepeat(vector<int>& arr) {
        vector<vector<int>> ans(arr.size(), vector<int>(2));
        stack<int> data;
        for (int i = 0; i < arr.size(); ++i) {
            while (!data.empty() && arr[data.top()] > arr[i]) {
                int popIdx = data.top();
                data.pop();
                int leftIdx = data.empty() ? -1 : data.top();
                ans[popIdx][0] = leftIdx;
                ans[popIdx][1] = i;
            }
            data.push(i);
        }
        while (!data.empty()) {
            int popIdx = data.top();
            data.pop();
            int leftIdx = data.empty() ? -1 : data.top();
            ans[popIdx][0] = leftIdx;
            ans[popIdx][1] = -1;
        }
        return ans;
    }

    vector<vector<int>> getNearLess(vector<int>& arr) {
        vector<vector<int>> ans(arr.size(), vector<int>(2));
        stack<vector<int>> data;
        for (int i = 0; i < arr.size(); ++i) {
            while (!data.empty() && arr[data.top().at(0)] > arr[i]) {
                vector<int> popIds = data.top();
                data.pop();
                int leftIdx = data.empty() ? -1 : data.top().back();
                for (int popi : popIds) {
                    ans[popi][0] = leftIdx;
                    ans[popi][1] = i;
                }
            }
            if (!data.empty() && arr[data.top().at(0)] == arr[i]) {
                data.top().push_back(i);
            } else {
                data.push({i});
            }
        }
        while (!data.empty()) {
            vector<int> popIs = data.top();
            data.pop();
            int leftIdx = data.empty() ? -1 : data.top().back();
            for (int popi : popIs) {
                ans[popi][0] = leftIdx;
                ans[popi][1] = -1;
            }
        }
        return ans;
    }
};
