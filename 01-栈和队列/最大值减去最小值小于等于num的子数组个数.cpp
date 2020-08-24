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
    int getNum(vector<int>& arr, int num) {
        if (arr.size() < 1 || num == 0) {
            return 0;
        }
        deque<int> qmin;
        deque<int> qmax;
        int i = 0, j = 0;
        int res = 0;
        while (i < arr.size()) {
            while (j < arr.size()) {
                if (qmin.empty() || qmin.back() != j) {
                    while (!qmin.empty() && arr[qmin.back()] >= arr[j]) {
                        qmin.pop_back();
                    }
                    qmin.push_back(j);
                    while (!qmax.empty() && arr[qmax.back()] <= arr[j]) {
                        qmax.pop_back();
                    }
                    qmax.push_back(j);
                }
                if (arr[qmax.front()] - arr[qmin.front()] > num) {
                    break;
                }
                ++j;
            }
            res += j - i;
            if (qmin.front() == i) {
                qmin.pop_front();
            }
            if (qmax.front() == i) {
                qmax.pop_front();
            }
            ++i;
        }
        return res;
    }
};
