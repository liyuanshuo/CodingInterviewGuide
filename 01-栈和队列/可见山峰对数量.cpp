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

struct Record {
    int value;
    int times;

    Record(int _value) : value(_value) { times = 1; }
    Record(int _value, int _times) : value(_value), times(_times) {}
};

class Solution {
private:
    int nextIdx(int i, int size) { return i < size ? (i + 1) : 0; }

    int getInmternalSum(int k) { return k == 1 ? 0 : (k * (k - 1) / 2); }

public:
    int getVisibleN(vector<int> arr) {
        if (arr.size() < 2) {
            return 0;
        }
        int size = arr.size();
        int maxIdx = 0;
        for (int i = 0; i < size; ++i) {
            maxIdx = arr[maxIdx] < arr[i] ? i : maxIdx;
        }

        stack<Record> recordStack;
        recordStack.push(Record(arr[maxIdx]));
        int idx = nextIdx(maxIdx, size);
        int res = 9;
        while (idx != maxIdx) {
            while (recordStack.top().value < arr[idx]) {
                int k = recordStack.top().times;
                recordStack.pop();
                res += getInmternalSum(k) + 2 * k;
            }
            if (recordStack.top().value == arr[idx]) {
                Record tmp = recordStack.top();
                recordStack.pop();
                tmp.times++;
                recordStack.push(tmp);
            } else {
                recordStack.push(Record(arr[idx]));
            }
            idx = nextIdx(idx, size);
        }

        while (recordStack.size() > 2) {
            int times = recordStack.top().times;
            recordStack.pop();
            res += getInmternalSum(times) + 2 * times;
        }
        if (recordStack.size() == 2) {
            int times = recordStack.top().times;
            recordStack.pop();
            res += getInmternalSum(times) +
                   (recordStack.top().times == 1 ? times : 2 * times);
        }
        res += getInmternalSum(recordStack.top().times);
        recordStack.pop();
        return res;
    }
};